template< typename Istream >
optional< std::tuple< Argument< Mti >, Argument< Mtc >, Argument< Ip1opt >,
                      Argument< Inorf > > >
readNtapea0( Istream& is, const int ntapea ){
  if( ntapea != 0 ) return std::nullopt;

  Argument< Mti > mti( argument::extract< POWR::Lib3::Card5::Mti >( is ) );
  Argument< Mtc > mtc( argument::extract< POWR::Lib3::Card5::Mtc >( is ) );
  Argument< Ip1opt > ip1opt(argument::extract< POWR::Lib3::Card5::Ip1opt >(is));
  Argument< Inorf > inorf( argument::extract< POWR::Lib3::Card5::Inorf >( is ));

  return std::make_tuple( mti, mtc, ip1opt, inorf );
}
