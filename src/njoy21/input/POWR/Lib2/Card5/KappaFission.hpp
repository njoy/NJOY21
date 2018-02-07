struct KappaFission{
  using Value_t = double;
  static std::string name(){ return "kappa fission"; }
  static std::string description(){
    return "The kappa fission parameter specifies the kappa fission value\n"
           "for this isotope at this temperature.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t kf ){
    return kf >= 0.0;
  }
};
