template< typename Istream >
optional< Argument< Dap > > readDap( Istream& is, const int mfcov ){
  if( mfcov != 33 ) return std::nullopt;

  return argument::extract< ERRORR::Rest::Card7::Dap >( is );
}
