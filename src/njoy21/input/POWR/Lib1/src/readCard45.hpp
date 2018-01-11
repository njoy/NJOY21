template< typename Istream >
optional< std::pair< Card4, Card5 > > readCard45( Istream& is, const int matd){
  if( matd <= 0 ) return std::nullopt;

  POWR::Lib1::Card4 card4( is );
  POWR::Lib1::Card5 card5( is );

  return std::make_pair( card4, card5 );
}
