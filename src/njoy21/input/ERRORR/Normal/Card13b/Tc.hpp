struct Tc {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "tc"; }
  static std::string description(){
    return "The tc parameter specifies the fission temperature of the\n"
           "analytic flux in eV.";
  }
  static bool verify( const Value_t tc ){
    return tc >= 0.0*electronVolt;
  }
};
