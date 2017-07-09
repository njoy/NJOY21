struct Emax {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "emax"; }

  static std::string description(){
    return
        "The emax argument specifies the maximum energy (in eV) to be used \n"
        "for the thermal scattering treatment. This value should be \n"
        "coordinated with the value of emax used in THERMR.\n"
        "\n"
        "The default is 1000 eV, indicating that the code will determine the \n"
        "upper limit from the data in MF=3 on the PENDF tape.";
  }

  static Value_t defaultValue(){ return 1.0*kilo( electronVolt ); }
  static bool verify( const Value_t& emax ){ 
    return emax > 0.0*electronVolt; 
  }
};
