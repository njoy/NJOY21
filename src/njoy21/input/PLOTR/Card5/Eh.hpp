struct Eh {
  using Value_t = float;
  static std::string name(){ return "eh"; }
  static std::string description(){
    return
      "The eh argument specifies the upper bound for the energy (x) axis.\n\n"
      "Checks that eh has a greater value than el.\n\n"
      "If using the default value, the default value should be used for el\n"
      "and xstep as well.";
  }
  static Value_t defaultValue( const float el ){
    return el;
  }
  static bool verify( const Value_t v, 
                      const float el ){
    return ( v >= el );
  }
};
