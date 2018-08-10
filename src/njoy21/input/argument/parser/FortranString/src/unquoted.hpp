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

