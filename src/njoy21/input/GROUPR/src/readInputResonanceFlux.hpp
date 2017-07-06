template< typename Istream>
static optional< Card8d > readInputResonanceFlux( 
    Istream& is, int iwt, const Card1& c1 ){
  if( iwt == 0 ){
    return Card8d( is, c1 );
  }
  else{
    return std::nullopt;
  }
}
