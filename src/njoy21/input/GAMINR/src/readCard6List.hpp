template< typename Istream>
static std::vector< Card6 > readCard6List( Istream& is ){
  std::vector< Card6 > card6List;

  card6List.emplace_back( is );

  if( card6List.back().mfd.value == -1 ) return card6List;

  do {
    card6List.emplace_back( is );
  } while ( card6List.back().mfd.value > 0 );

  if( card6List.back().mfd.value == -1 ){
    Log::info( "Mfd value is -1 after reading 1 or more sections." );
    throw std::exception();
  }

  card6List.pop_back();
  return card6List;
}
