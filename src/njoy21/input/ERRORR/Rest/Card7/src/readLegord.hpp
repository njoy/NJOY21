template< typename Istream >
optional< Argument< Legord > > readLegord( Istream& is, const int mfcov ){
  if( mfcov != 34 ) return std::nullopt;

  return argument::extract< ERRORR::Rest::Card7::Legord >( is );
}
