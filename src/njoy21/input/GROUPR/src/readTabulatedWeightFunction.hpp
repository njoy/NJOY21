template< typename Istream>
static optional< Card8b > readTabulatedWeightFunction( Istream& is, int iwt ){
  if( abs( iwt ) == 1 ){
    return Card8b( is );
  }
  else{
    return std::nullopt;
  }
}
