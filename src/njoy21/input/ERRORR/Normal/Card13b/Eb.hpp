struct Eb {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "eb"; }
  static std::string description(){
    return "The eb parameter specifies the thermal break of the analytic\n"
           "flux in eV.";
  }
  static bool verify( const Value_t eb ){
    return eb >= 0.0*electronVolt;
  }
};
