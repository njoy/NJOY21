struct KappaCapture{
  using Value_t = double;
  static std::string name(){ return "kappa capture"; }
  static std::string description(){
    return "The kappa capture parameter specifies the kappa capture value\n"
           "for this isotope at this temperature.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t kc ){
    return kc >= 0.0;
  }
};
