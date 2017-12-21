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

  if( card13List.size() == 0 ){
    Log::error( "No values were provided for PLOTR Card 13 when they were"
                "expected." );
    throw std::exception();
  }

  return card13List;
}
