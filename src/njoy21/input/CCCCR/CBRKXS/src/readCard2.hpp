template< typename Istream >
optional< Card2 > readCard2( Istream& is, const int nti ){
  if( nti < 0 ) return std::nullopt;

  return Card2( is, nti );
}
