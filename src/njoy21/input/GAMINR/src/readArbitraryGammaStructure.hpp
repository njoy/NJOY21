template< typename Istream>
static optional< Card4 > readArbitraryGammaStructure(
    Istream& is, int igg ){
  if( igg == 1 ){
    Card4 card4( is );

    return card4;
  }
  else{
    return std::nullopt;
  }
}
