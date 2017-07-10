template< typename Istream>
static Card8Variant readFluxParameters( Istream& is, 
                                                    int iwt, 
                                                     const Card1& c1 ){
  switch( std::abs(iwt) ){
    case 1:
      return Card8Variant( Card8b( is ) );
    case 4:
      return Card8Variant( Card8c( is ) );
    case 0:
      return Card8Variant( Card8d( is, c1 ) );
    default:
      return std::monostate{};
  }
}

