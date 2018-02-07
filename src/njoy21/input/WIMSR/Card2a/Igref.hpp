struct Igref {
  using Value_t = int;
  static std::string name(){ return "igref"; }
  static std::string description(){
    return "The igref format specifies which group is used as the reference\n"
           "for normalizing the flux.  The default value is the lowest-energy\n"
           "fast energy group.";
  }
  static Value_t defaultValue( const Value_t nfg, const Value_t ){
    return nfg;
  }
  static bool verify( const Value_t igref, const Value_t, const Value_t ngnd ){
    return igref > 0 and igref < ngnd;
  }
};
