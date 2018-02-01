struct Atem {
  using Value_t = std::vector< Quantity< Kelvin > >;
  static std::string name(){ return "atem"; }
  static std::string description(){
    return "The atem parameter specifies the values of the desired\n"
           "temperatures in Kelvin.";
  }
  static bool verify( const Value_t atem, const int ){
    for( auto t : atem ){
      if( t < 0.0*dimwits::kelvin ) return false;
    }
    return true;
  }
};
