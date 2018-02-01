struct Temp {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "temp"; }
  static std::string description(){
    return "The temp parameter specifies the isotope temperature in Kelvin.";
  }
  static bool verify( const Value_t temp ){
    return temp >= 0.0*dimwits::kelvin;
  }
};
