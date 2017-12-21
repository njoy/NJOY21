template< typename Istream>
static optional< Card5 > readArbitraryWeights(
    Istream& is, int iwt ){
  if( iwt == 1 ){
    Card5 card5( is );

    return card5;
  }
  else{
    return std::nullopt;
  }
}
