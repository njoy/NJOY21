template< typename Istream>
optional< DummyMF33 > readDummyMF33( Istream& is, const int nendf ){
  if( nendf != 999 ) return std::nullopt;

  return DummyMF33( is );
}
