struct Temp {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "temp"; }
  static std::string description() {
    return
      "temp specifies the temperature in Kelvin at which the scattering law\n"
      "should be prepared. Each temp input initiates a temperature loop\n"
      "(which consists of cards 10 - 18), and there should be ntempr loops,\n"
      "where ntempr is a Card3 input. \n"
      "\n"
      "If temp is non-negative, then cards 11 - 18 will be read to gather\n"
      "temperature-specific evaluation parameters. If temp is negative,\n"
      "cards 11 - 18 will not be read, and parameters from preceding loop\n"
      "are used. Obviously, temp must be positive for the first loop\n"
      "iteration"; 
  }
  
  static bool verify( const Value_t& ){ return true; }
};
