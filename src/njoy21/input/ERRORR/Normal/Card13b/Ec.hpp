struct Ec {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "ec"; }
  static std::string description(){
    return "The ec parameter specifies the fission break of the analytic\n"
           "flux in eV.";
  }
  static bool verify( const Value_t ec ){
    return ec >= 0.0*electronVolt;
  }
};
