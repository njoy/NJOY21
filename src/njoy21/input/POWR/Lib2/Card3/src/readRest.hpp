template< typename Istream >
optional< std::pair< Argument< Name >, Argument< Idtemp > > >
readRest( Istream& is, const int matd ){
  if( matd == 0 ) return std::nullopt;

  return std::make_pair( argument::extract< POWR::Lib2::Card3::Name >( is ),
                         argument::extract< POWR::Lib2::Card3::Idtemp >( is ) );
}
