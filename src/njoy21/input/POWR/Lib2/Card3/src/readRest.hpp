template< typename Istream >
optional< std::pair< Argument< Idtemp >, Argument< Name > > >
readRest( Istream& is, const int matd ){
  if( matd == 0 ) return std::nullopt;

  auto idtemp = argument::extract< POWR::Lib2::Card3::Idtemp >( is );
  auto name = argument::extract< POWR::Lib2::Card3::Name >( is );

  return std::make_pair( std::move( idtemp ), std::move( name ) );
}
