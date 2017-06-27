template< typename Istream>
static optional< Card8d > readInputResonanceFlux( Istream& is, int iwt ){
  if( iwt == 0 ){
    return Card8d( is );
  }
  else{
    return std::nullopt;
  }
}
