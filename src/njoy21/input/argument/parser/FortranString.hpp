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
