template< typename Istream >
optional< Argument< Irespr > > readIrespr( Istream& is, const int mfcov ){
  if( mfcov != 32 ) return std::nullopt;

  return argument::extract< ERRORR::Rest::Card7::Irespr >( is );
}
