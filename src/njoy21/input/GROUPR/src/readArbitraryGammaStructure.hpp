template< typename Istream>
static optional< std::pair< Card7a, Card7b > > readArbitraryGammaStructure(
    Istream& is, int igg ){
  if( igg == 1 ){
    Card7a card7a( is );

    return std::make_pair< Card7a, Card7b >( 
        std::move( card7a ), Card7b( is, card7a.ngg ) );
  }
  else{
    return std::nullopt;
  }
}
