template< typename Istream>
static optional< Card8a > readFluxCalculatorParameters( 
    Istream& is, int iwt, const Card1& c1){
  if( iwt < 0 ){
    return Card8a( is, c1 );
  }
  else{
    return std::nullopt;
  }
}
