template< typename Istream >
optional< Card3 > readCard3( Istream& is, const int nzi ){
  if( nzi < 0 ) return std::nullopt;

  return Card3( is, nzi );
}
