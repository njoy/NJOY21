template< typename Istream>
static optional< std::vector< Card13 > > 
readCard13List( Istream& is, const int nform ){
  if( nform != 0 ) return std::nullopt;

  std::vector< Card13 > card13List;
  Card13 tmp13( is );

  while( tmp13.xdata.value ){
    card13List.push_back( std::move(tmp13) );
    tmp13 = PLOTR::Card13( is );
  }
  return card13List;
}
