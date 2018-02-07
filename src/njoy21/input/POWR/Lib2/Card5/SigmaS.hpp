struct SigmaS{
  using Value_t = double;
  static std::string name(){ return "sigma s"; }
  static std::string description(){
    return "The sigma s parameter specifies the sigma s value for this\n"
           "isotope at this temperature.  If it is set to zero (0), the\n"
           "value is set to the scattering cross section at group 35.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t sigmas ){
    return sigmas >= 0.0;
  }
};
