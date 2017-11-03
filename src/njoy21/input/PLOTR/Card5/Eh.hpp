struct Eh {
  using Value_t = optional< double >;
  static std::string name(){ return "eh"; }
  static std::string description(){
    return
      "The eh argument specifies the upper bound for the energy (x) axis.\n\n"
      "Checks that eh has a greater value than el.\n\n"
      "If using the default value, the default value should be used for el\n"
      "and xstep as well.";
  }
  static Value_t defaultValue( const Value_t el ){
    if( el != std::nullopt ){
      Log::info( "When using a default in PLOTR::Card5, all values should use\n"
                 "their default value.\n" );
      std::exception e;
      throw e;
    }
    return std::nullopt;
  }
  static bool verify( const Value_t v, const Value_t el ){
    return ( el != std::nullopt and *v >= *el );
  }
};
