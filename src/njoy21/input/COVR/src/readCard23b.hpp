template< typename Istream >
optional< std::tuple< Card2b, Card3b, Card3c > >
                                     readCard23b( Istream& is, const int nout ){
  if( nout <= 0 ) return std::nullopt;

  Card2b card2b( is );

  Card3b card3b( is );

  Card3c card3c( is );

  return std::make_tuple( std::move( card2b ), std::move( card3b ),
                          std::move( card3c ) );
}
