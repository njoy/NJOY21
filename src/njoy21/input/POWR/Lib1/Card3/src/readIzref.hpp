template< typename Istream >
optional< Izref > readIzref( Istream& is, const int matd ){
  if( matd < 0 ) return std::nullopt;
  return argument::extract< POWR::Lib1::Card3::Izref >( is );
}
