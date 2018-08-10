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

