struct Mt1 {
  using Value_t = int;
  static std::string name(){ return "mt1"; }

  static std::string description(){
    return
      "mt must be an integer greater than or equal to zero. The mt values\n"
      "are usually just the endf mt numbers for the reaction, however there\n"
      "are special values available to request the weighting flux, the\n"
      "steady state and delayed components of the fission neutron spectrum,\n"
      "or the delayed fission neutron yield."; 
  }
  static Value_t defaultValue(){ return 0; }
};

