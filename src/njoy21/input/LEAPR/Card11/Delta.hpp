struct Delta {
  using Value_t = Quantity< ElectronVolts >;
  static std::string name(){ return "delta"; }
  static std::string description(){
    return
      "The delta input is the interval spacing for the S(a,b) grid\n"
      "in eV. delta must be greater than zero.";
  }
  static bool verify( const Value_t& delta ){ 
    return delta > ( 0.0 * dimwits::electronVolts);
  }
};
