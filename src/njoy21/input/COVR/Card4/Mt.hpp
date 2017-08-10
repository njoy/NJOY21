struct Mt {
  using Value_t = int;
  static std::string name(){ return "mt"; }

  static std::string description(){
    return
      "mt must be an integer greater than or equal to zero. The mt values\n"
      "are usually just the endf mt numbers for the reaction, however there\n"
      "are special values available to request the weighting flux, the\n"
      "steady state and delayed components of the fission neutron spectrum,\n"
      "or the delayed fission neutron yield."; 
  }

  static bool verify( Value_t i ){ return 0 <= i; } 
};

