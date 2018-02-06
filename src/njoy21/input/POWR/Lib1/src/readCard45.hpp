template< typename Istream >
optional< std::pair< Card4, Card5 > > readCard45( Istream& is, const int matd ){
  if( matd <= 0 ) return std::nullopt;

  Card4 card4( is );
  Card5 card5( is );

  return std::make_pair( std::move( card4 ), std::move( card5 ) );
}
