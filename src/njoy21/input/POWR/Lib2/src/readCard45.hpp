template< typename Istream >
optional< std::pair< Card5, Card4 > > readCard45( Istream& is, const int matd ){
  if( matd == 0 ) return std::nullopt;

  return std::make_pair( Card5( is ), Card4( is ) );
}
