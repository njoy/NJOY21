template< typename Istream>
optional< Dummy > readDummy( Istream& is, const int nendf ){
  if( nendf != 999 ) return std::nullopt;

  return Dummy( is );
}
