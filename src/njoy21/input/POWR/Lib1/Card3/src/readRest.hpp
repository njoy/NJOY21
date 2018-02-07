template< typename Istream >
optional< std::tuple< Argument< Rtemp >, Argument< Iff >, Argument< Nsgz >,
                      Argument< Izref > > >
readRest( Istream& is, const int matd ){
  if( matd <= 0 ) return std::nullopt;
  Argument< Rtemp > rtemp( argument::extract< POWR::Lib1::Card3::Rtemp >( is ));
  Argument< Iff > iff( argument::extract< POWR::Lib1::Card3::Iff >( is ) );
  Argument< Nsgz > nsgz( argument::extract< POWR::Lib1::Card3::Nsgz >( is ) );
  Argument< Izref > izref( argument::extract< POWR::Lib1::Card3::Izref >( is ));
  return std::make_tuple( std::move( rtemp ), std::move( iff ),
                          std::move( nsgz ), std::move( izref ) );
}
