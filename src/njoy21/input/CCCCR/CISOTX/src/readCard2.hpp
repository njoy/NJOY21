template< typename Istream >
optional< Card2 > readCard2( Istream& is, const int ngroup, const int ichix ){
  if( ichix != 1 ) return std::nullopt;

  return Card2( is, ngroup );
}
