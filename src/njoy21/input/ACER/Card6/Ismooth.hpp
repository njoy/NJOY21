struct Ismooth {
  using Value_t = int;
  static std::string name(){ return "ismooth"; }

  static std::string description(){
    return
        "The ismooth argument isused to switch on or off the sqrt(e) \n"
        "smoothing operation for cm emission spectra and for histogram \n"
        "delayed neutron spectra at low energies. A value 0 switches it off \n"
        "while a value of 1 switches it on.";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( Value_t i ){ return ( i == 0 ) or ( i == 1 ); }
};

