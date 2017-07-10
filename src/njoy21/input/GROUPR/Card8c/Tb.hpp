struct Tb {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "tb"; }

  static std::string description(){ 
    return 
        "The tb argument specifies the temperature (in eV) of the thermal \n"
        "spectrum when calculating a weight function.";
  }

  static bool verify( const Value_t T ){ return T > 0.0*electronVolt; }
};
