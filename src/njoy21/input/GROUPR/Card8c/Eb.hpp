struct Eb {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "eb"; }

  static std::string description(){ 
    return 
        "The eb argument specifies the energy (in eV) of the thermal break \n"
        "when calculating a weight function.";
  }

  static bool verify( const Value_t E ){ return E > 0.0*electronVolt; }
};
