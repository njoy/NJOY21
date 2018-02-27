struct Tb {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "tb"; }
  static std::string description(){
    return "The tb parameter specifies the thermal temperature of the\n"
           "analytic flux in eV.";
  }
  static bool verify( const Value_t tb ){
    return tb >= 0.0*electronVolt;
  }
};
