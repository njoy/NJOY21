template< typename Istream >
optional< std::pair< Pos, Posr > > readMode0( Istream& is, const int mode ){
  if( mode != 0 ) return std::nullopt;

  Pos pos( argument::extract< POWR::Lib3::Card5::Pos >( is ) );
  Posr posr( argument::extract< POWR::Lib3::Card5::Posr >( is ) );

  return std::make_pair( pos, posr );
}
