struct Xspo{
  using Value_t = double;
  static std::string name(){ return "xspo"; }
  static std::string description(){
    return "The xspo parameter specifies the average potential scattering\n"
           "cross section.";
  }
  static bool verify( const Value_t xspo ){
    return xspo >= 0.0;
  }
};
