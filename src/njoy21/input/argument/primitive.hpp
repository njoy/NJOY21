namespace primitive {

template< typename Char >
void validate( iRecordStream<Char>& is ){
  if ( is.good() and not is.eof() ){
    const auto character = is.peek();
    if ( std::isspace( character ) or character == '/' ){ return; }
    is.setstate( std::ios_base::failbit );
  }
}

template< typename Char, typename Unit, typename MagnitudeType >
iRecordStream<Char>& operator>>( iRecordStream<Char>& is, Quantity< Unit, MagnitudeType >& quantity ){
  is >> quantity.value; return is;
}

template< typename Char, typename First, typename Second >
iRecordStream<Char>& operator>>( iRecordStream<Char>& is, std::pair< First, Second >& pair ){
  is >> pair.first;
  validate(is);
  if ( is.good() ){ is >> pair.second; }
  return is;
}

template< typename Char, typename Value >
iRecordStream<Char>& operator>>( iRecordStream<Char>& is, std::vector< Value >& vector ){
  for ( auto& entry : vector ){
    is >> entry;
    validate(is);
    if ( is.fail() ){
      vector.pop_back();
      break;
    }
  }
  return is;
}

template< typename T >
struct Type {
  using Data_t = T;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>&, T&, Args&&... );
};

template< typename T >
template< typename Char, typename... Args >
bool Type<T>::read( iRecordStream<Char>& is, T& i, Args&&... ){
  is >> i; validate(is); return true;
}

template< typename Char >
class FortranString {
  std::basic_string<Char>& core;
  typename std::char_traits<Char>::int_type buffer;
  
  void quoted( std::basic_istream< Char >& is ){
    do {
      this->core.push_back( is.get() );
    } while ( is.good() and ( core.back() != '\'') );
    if ( is.good() ){
      this->core.pop_back();
      is.peek(); // pull the next character into the buffer
    }
    if ( is.eof() ){
      is.setstate( std::ios::failbit );
    }
  }

  void unquoted( std::basic_istream< Char >& is ){
    do {
      this->core.push_back( this->buffer );
      this->buffer = is.get();
      if ( std::isspace( this->buffer ) or this->buffer == '/' ){
	is.unget();
	return;
      }
    } while ( is.good() );
    if ( ( not is.good() ) and ( not this->core.empty() ) ){
      is.clear();
    }
  }
  
public:
  FortranString( std::basic_string<Char>& core ) : core( core ){
    this->core.clear();
  }
  
  void read( std::basic_istream< Char >& is ){
    do {
      this->buffer = is.get();
    } while ( is.good() and std::isspace( this->buffer ) );
    if ( this->buffer =='/' ){
      is.unget();
      is.setstate( std::ios::failbit );
    }
    if ( not is.good() ){ return; }    
    ( this->buffer == '\'' ) ? this->quoted(is) : this->unquoted(is);
  }
};

template< typename Char >
std::basic_istream< Char >&
operator>>( std::basic_istream< Char >& is, FortranString<Char> string ){
  string.read(is); return is;
}

template<>
template< typename Char, typename... Args >
inline bool
Type< std::string >::read( iRecordStream<Char>& is, std::string& string, Args&&... ){
  is >> FortranString<Char>( string );

  bool wasQuoted = (is.buffer.back() == '\'') and ( string.back() != '\'');

  if ( wasQuoted ){
    validate(is);
    if ( is.fail() and ( is.buffer.back() == '\'' ) ){ is.clear(); }
    if ( not is.fail() ){
      string.erase( std::remove( std::begin(string), std::end(string), '\n' ),
		    std::end(string) );
    }
  }
  return true;
}

template< typename T >
struct Type< std::vector<T> > {
  using Data_t = std::vector<T>;
  
  template< typename Char, typename Arg, typename... Args >
  static bool read( iRecordStream<Char>& is , Data_t& vector, const Arg& size, Args&&... ){
    vector.resize( size.value );
    is >> vector;
    return true;
  }
};

template< typename Core >
struct Required : protected Core {
  using Data_t = typename Core::Data_t;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Data_t& d, Args&&... args ){
    Core::read( is, d, std::forward<Args>(args)... );
    if ( is.fail() ){
      is.eof() ? throw std::ios_base::failure("") : throw std::domain_error("");
    }
    return true;
  }
};

template< typename Core >
struct Optional : protected Core {
  using Data_t = typename Core::Data_t;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Data_t& d , Args&&... args ){
    auto success = Core::read( is, d, std::forward<Args>(args)... );
    if ( not is.fail() ){ return success; }
    is.clear();
    return ( is.peek() == '/' ) ? false :
                                  throw std::domain_error("");
  }
};

template< typename Core, typename Child = typename Core::Child_t >
struct Discriminating : protected Core {
  using Child_t = Child;
  using Data_t = typename Core::Data_t;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Data_t& d, Args&&... args ){
    if ( Core::read( is, d, std::forward<Args>(args)... ) ){
      if ( not Child::verify( d, std::forward<Args>(args)... ) ){
	throw std::domain_error("");
      }
      return true;
    }
    return false;
  }
};


template< typename Core, typename Child = typename Core::Child_t >
struct Defaulted : protected Core {
  using Child_t = Child;
  using Data_t = typename Core::Data_t;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Data_t& d, Args&&... args ){
    if ( not Optional<Core>::read( is, d, std::forward<Args>(args)... ) ){
      d = Child::defaultValue( std::forward<Args>(args)... );
      return false;
    }
    return true;
  }
};

template< typename T, typename = void >
struct HasDefault : public std::integral_constant< bool, false >{};

template< typename T >
struct HasDefault< T, utility::void_t< decltype( &T::defaultValue ) > > :
    public std::integral_constant< bool, true >{};

template< typename T, typename = void >
struct RequiresVerification : public std::integral_constant< bool, false >{};

template< typename T >
struct RequiresVerification< T, utility::void_t< decltype( &T::verify ) > > :
    public std::integral_constant< bool, true >{};

template< typename Child, bool, bool >
struct Parent;

template< typename Child >
struct Parent< Child, false, false >{
  using type = Required< Type< typename Child::Value_t > >;
};
    
template< typename Child >
struct Parent< Child, false, true >{ 
  using type = Discriminating
               < Required< Type< typename Child::Value_t > >, Child >;
};

template< typename Child >
struct Parent< Child, true, false >{
  using type = Defaulted< Type< typename Child::Value_t >, Child >;
};
    
template< typename Child >
struct Parent< Child, true, true >{
  using type = 
    Defaulted
    < Discriminating
      < Optional
        < Type
	  < typename Child::Value_t > >, Child > >;
};
    
template< typename Child, bool defaults, bool verifies >
using Parent_t = typename Parent< Child, defaults, verifies >::type;
    
}
