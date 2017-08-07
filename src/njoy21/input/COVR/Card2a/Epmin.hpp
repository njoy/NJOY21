struct Epmin {
  using Value_t = double;
  
  static std::string name(){ return "epmin"; }
  static std::string description(){ 
    return
      "The epmin input specifies the lowest energy of interest. This\n"
      "parameter is used to eliminate uninteresting energy regions from\n"
      "the correlation and standard deviation plots, or to display high-\n"
      "energy regions with greater resolution.";
  }  
  static Value_t defaultValue( ){ return 0.0; }
  
  static bool verify( const Value_t epmin ){ return epmin >= 0.0; }
};
