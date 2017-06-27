template< typename Istream>
static optional< Card8a > readFluxCalculatorParameters( Istream& is, int iwt ){
  if( iwt < 0 ){
    return Card8a( is );
  }
  else{
    return std::nullopt;
  }
}
