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

