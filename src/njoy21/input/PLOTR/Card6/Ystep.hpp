struct Ystep {
  using Value_t = optional< double >;
  static std::string name(){ return "ystep"; }
  static std::string description(){
    return
      "The ystep argument specifies the spacing for tics on the y-axis.\n\n"
      "The default behavior is automatic scaling.  The value is ignored if\n"
      "log scaling is used.";
  }
  static Value_t defaultValue( const Value_t yl, const Value_t yh ){
    if( yl != std::nullopt or yh != std::nullopt ){
      Log::info( "When using default values in PLOTR::Card6, the default\n"
                 "values should be used for all parameters.");
      std::exception e;
      throw e;
    }
    return std::nullopt;
  }
  static bool verify( const Value_t v, const Value_t, const Value_t ){
    return ( *v > 0 );
  }
};
