template< typename Char >
class FortranString {
  std::basic_string<Char>& core;
  typename std::char_traits<Char>::int_type buffer;
  char quote;

  bool isQuote( char c ){
    if ( ( c == '\'' ) or ( c == '*' ) ){
      quote = c;
      return true;
    }
    return false;
  }

  void quoted( std::basic_istream< Char >& is ){
    do {
      char c = is.get();
      if ( c != '\n' ) this->core.push_back( c );
    } while ( is.good() and ( core.back() != quote ) );
    if ( is.good() ){
      this->core.pop_back();
      is.peek(); // pull the next character into the buffer
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
    ( this->isQuote( this->buffer ) ) ? this->quoted( is )
                                      : this->unquoted( is );
  }
};
