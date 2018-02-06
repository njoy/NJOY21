struct Rstep {
  using Value_t = optional< double >;
  static std::string name(){ return "rstep"; }
  static std::string description(){
    return
      "The rstep argument specifies the spacing for tics on the alternate\n"
      "y-axis or the z-axis.\n\n"
      "The default behavior is automatic scaling.  The value is ignored if\n"
      "log scaling is used.";
  }
  static Value_t defaultValue( const Value_t rbot ){
    if( rbot ){
      Log::error( "When using default values in PLOTR::Card7, all values"
                  "should be defaulted." );
      throw std::exception();
    }
    return std::nullopt;
  }
  static bool verify( const Value_t v, const Value_t ){
    return *v > 0.0;
  }
};
