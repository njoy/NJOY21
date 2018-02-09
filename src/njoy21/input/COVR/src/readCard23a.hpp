template< typename Istream >
optional< std::tuple< Card2, optional< Card2z >, Card2a, Card3a > >
                                     readCard23a( Istream& is, const int nout ){
  if( nout > 0 ) return std::nullopt;

  Card2 card2( is );

  optional< Card2z > card2z;

  if( card2.icolor.value == 2 ){
    card2z = Card2z( is );
  } else {
    card2z = std::nullopt;
  }

  Card2a card2a( is );

  Card3a card3a( is );

  return std::make_tuple( std::move( card2 ), std::move( card2z ),
                          std::move( card2a ), std::move( card3a ) );
}
