template< typename Istream >
optional< Argument< Irespr > > readIrespr( Istream& is, const int mfcov ){
  if( mfcov != 33 ) return std::nullopt;

  return argument::extract< ERRORR::Normal::Card7::Irespr >( is );
}
