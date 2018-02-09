template< typename Istream >
optional< Card3 > readCard3( Istream& is, const int ngroup, const int ichix ){
  if( ichix < 2 ) return std::nullopt;

  return Card3( is, ngroup, ichix );
}
