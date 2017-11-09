struct Xstep {
  using Value_t = optional< double >;
  static std::string name(){ return "xstep"; }
  static std::string description(){
    return
      "The xstep argument specifies the spacing for tics on the energy (x)\n"
      "axis.\n\n"
      "The default behavior is automatic scaling.  If the default is used,\n"
      "the default should be used for el and eh as well.\n\n"
      "The value is ignored if log scaling is used.";
  }
  static Value_t defaultValue( const Value_t el ){
    if( el != std::nullopt ){
      Log::info( "When using a default value in PLOTR::Card5, all values\n"
                 "should use their default value.\n" );
      std::exception e;
      throw e;
    }
    return std::nullopt;
  }
  static bool verify( const Value_t v, const Value_t ){
    return *v > 0.0;
  }
};
