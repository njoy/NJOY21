template< typename Istream >
optional< std::pair< Argument< Ifissp >, Argument< Efmean > > >
readIfisspEfmean( Istream& is, const int mfcov ){
  if( mfcov != 35 ) return std::nullopt;

  auto ifissp = argument::extract< ERRORR::Rest::Card7::Ifissp >( is );

  auto efmean = argument::extract< ERRORR::Rest::Card7::Efmean >( is,
                                                           this->ifissp.value );

  return std::make_pair( std::move( ifissp ), std::move( efmean ) );
}
