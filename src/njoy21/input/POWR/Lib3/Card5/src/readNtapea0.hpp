template< typename Istream >
optional< std::tuple< Mti, Mtc, Ip1opt, Inorf > >
                                    readNtapea( Istream& is, const int ntapea ){
  if( ntapea != 0 ) return std::nullopt;

  Mti mti( argument::extract< POWR::Lib3::Card5::Mti >( is ) );
  Mtc mtc( argument::extract< POWR::Lib3::Card5::Mtc >( is ) );
  Ip1opt ip1opt( argument::extract< POWR::Lib3::Card5::Ip1opt >( is ) );
  Inorf inorf( argument::extract< POWR::Lib3::Card5::Inorf >( is ) );

  return std::make_tuple( mti, mtc, ip1opt, inorf );
}
