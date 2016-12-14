namespace primitive {

template< typename Istream >
void validate( Istream& is ){
  if ( is.good() and not is.eof() ){
    const auto character = is.peek();
    if ( std::isspace( character ) or character == '/' ){ return; }
    is.setstate( std::ios_base::failbit );
  }
}

template< typename Istream, typename Unit, typename MagnitudeType >
Istream& operator>>( Istream& is, Quantity< Unit, MagnitudeType >& quantity ){
  is >> quantity.value; return is;
}

template< typename Istream, typename First, typename Second >
Istream& operator>>( Istream& is, std::pair< First, Second >& pair ){
  is >> pair.first;
  validate(is);
  if ( is.good() ){ is >> pair.second; }
  return is;
}

template< typename Istream, typename Value >
Istream& operator>>( Istream& is, std::vector< Value >& vector ){
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
  
  template< typename Istream, typename... Args >
  static bool read( Istream&, T&, Args&&... );
};

template< typename T >
template< typename Istream, typename... Args >
bool Type<T>::read( Istream& is, T& i, Args&&... ){
  is >> i; validate(is); return true;
}

template<>
template< typename Istream, typename... Args >
inline bool
Type< std::string >::read( Istream& is, std::string& string, Args&&... ){
  is >> std::quoted( string, '\'', char(33) );
  validate(is);
  if ( not is.fail() ){
    string.erase( std::remove( std::begin(string), std::end(string), '\n' ),
                  std::end(string) );
  }
  return true;
}

template< typename T >
struct Type< std::vector<T> > {
  using Data_t = std::vector<T>;
  
  template< typename Istream, typename Arg, typename... Args >
  static bool read( Istream& is , Data_t& vector, const Arg& size, Args&&... ){
    vector.resize( size.value );
    is >> vector;
    return true;
  }
};

template< typename Core >
struct Required : protected Core {
  using Data_t = typename Core::Data_t;
  template< typename Istream, typename... Args >
  static bool read( Istream& is, Data_t& d, Args&&... args ){
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
  template< typename Istream, typename... Args >
  static bool read( Istream& is, Data_t& d , Args&&... args ){
    Core::read( is, d, std::forward<Args>(args)... );
    return is.fail() ? is.eof() ? false : throw std::domain_error("") : true;
  }
};

template< typename Core, typename Child = typename Core::Child_t >
struct Discriminating : protected Core {
  using Child_t = Child;
  using Data_t = typename Core::Data_t;
  template< typename Istream, typename... Args >
  static bool read( Istream& is, Data_t& d, Args&&... args ){
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
  template< typename Istream, typename... Args >
  static bool read( Istream& is, Data_t& d, Args&&... args ){
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
