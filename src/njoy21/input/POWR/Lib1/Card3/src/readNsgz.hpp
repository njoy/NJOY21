template< typename Istream >
optional< Argument< Nsgz > > readNsgz( Istream& is, const int matd ){
  if( matd < 0 ) return std::nullopt;
  return argument::extract< POWR::Lib1::Card3::Nsgz >( is );
}
