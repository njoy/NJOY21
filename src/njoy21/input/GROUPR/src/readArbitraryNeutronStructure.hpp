template< typename Istream>
static optional< std::pair< Card6a, Card6b > > readArbitraryNeutronStructure(
    Istream& is, int ign ){
  if( ign == 1 ){
    Card6a card6a( is );

    return std::make_pair< Card6a, Card6b >( 
        std::move( card6a ), Card6b( is, card6a.ngn ) );
  }
  else{
    return std::nullopt;
  }
}
