template< typename Char >
void validate( iRecordStream<Char>& is ){
  if ( is.good() and not is.eof() ){
    const auto character = is.peek();
    if ( std::isspace( character ) or character == '/' ){ return; }
    is.setstate( std::ios_base::failbit );
  }
}
