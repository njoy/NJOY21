template< typename Istream>
static optional< Card8c > readAnalyticFluxParameters( Istream& is, int iwt ){
  if( abs( iwt ) == 4 ){
    return Card8c( is );
  }
  else{
    return std::nullopt;
  }
}
