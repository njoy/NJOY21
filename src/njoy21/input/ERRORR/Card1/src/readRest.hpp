template< typename Istream >
optional< std::tuple< Argument< Npend >, Argument< Ngout >, Argument< Nout >,
                      Argument< Nin >, Argument< Nstan > > >
readRest( Istream& is, const int nendf ){

  if( nendf == 999 ) return std::nullopt;

  Argument< Npend > npend(
                       argument::extract< ERRORR::Card1::Npend >( is, nendf ) );
  Argument< Ngout > ngout( argument::extract< ERRORR::Card1::Ngout >( is, nendf,
                                                          this->npend.value ) );
  Argument< Nout > nout( argument::extract< ERRORR::Card1::Nout >( is, nendf,
                                       this->npend.value, this->ngout.value ) );
  Argument< Nin > nin( argument::extract< ERRORR::Card1::Nin >( is, nendf,
                     this->npend.value, this->ngout.value, this->nout.value ) );
  Argument< Nstan > nstan( argument::extract< ERRORR::Card1::Nstan >( is, nendf,
    this->npend.value, this->ngout.value, this->nout.value, this->nin.value ) );

  return std::make_tuple( std::move( npend ), std::move( ngout ),
                          std::move( nout ), std::move( nin ),
                          std::move( nstan ) );
}
