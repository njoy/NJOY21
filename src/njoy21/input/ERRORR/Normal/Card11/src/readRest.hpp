template< typename Istream >
optional< std::tuple< Argument< Mtb >, Argument< Matc >, Argument< Mtc > > >
                                        readRest( Istream& is, const int matb ){
  if( matb == 0 ) return std::nullopt;

  auto mtb = argument::extract< ERRORR::Normal::Card11::Mtb >( is );
  auto matc = argument::extract< ERRORR::Normal::Card11::Matc >( is );
  auto mtc = argument::extract< ERRORR::Normal::Card11::Mtc >( is );

  return std::make_tuple(std::move( mtb ), std::move( matc ), std::move( mtc ));
}
