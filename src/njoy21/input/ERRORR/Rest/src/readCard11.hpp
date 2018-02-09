template< typename Istream >
optional< Card11 > readCard11( Istream& is, const int nstan ){
  if( nstan == 0 ) return std::nullopt;

  return Card11( is );
}
