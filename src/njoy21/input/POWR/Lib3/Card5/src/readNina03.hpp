template< typename Istream>
optional< std::pair< Ires, Sigp > > readNina03( Istream& is, const int nina ){
  if( nina != 3 ) return std::nullopt;

  Ires ires( argument::extract< POWR::Lib3::Card5::Ires >( is ) );
  Sigp sigp( argument::extract< POWR::Lib3::Card5::Sigp >( is ) );

  return std::make_pair( ires, sigp );
}
