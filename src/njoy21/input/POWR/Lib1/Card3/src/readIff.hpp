template< typename Istream >
optional< Argument< Iff > > readIff( Istream& is, const int matd ){
  if( matd < 0 ) return std::nullopt;
  return argument::extract< POWR::Lib1::Card3::Iff >( is );
}
