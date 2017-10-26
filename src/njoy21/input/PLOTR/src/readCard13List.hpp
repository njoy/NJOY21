template< typename Istream>
static optional< std::vector< Card13 > > 
                                 readCard13List( Istream& is, const int nform ){
  if( nform != 0 ) return std::nullopt;

  optional< std::vector< Card13 > > card13List;

  do {
    Card13 tmp13( is );
    card13List->emplace_back( tmp13 );
  } while ( card13List->back().xdata.value );
  card13List->pop_back();
  return card13List;
}
