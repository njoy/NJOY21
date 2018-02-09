struct Epmin {
  using Value_t = Quantity< ElectronVolt >;
  
  static std::string name(){ return "epmin"; }
  static std::string description(){ 
    return
      "The epmin input specifies the lowest energy of interest (eV). This\n"
      "parameter is used to eliminate uninteresting energy regions from\n"
      "the correlation and standard deviation plots, or to display high-\n"
      "energy regions with greater resolution.";
  }  
  static Value_t defaultValue(){ return 0.0*electronVolt; }
  
  static bool verify( const Value_t epmin ){ return epmin >= 0.0*electronVolt; }
};
