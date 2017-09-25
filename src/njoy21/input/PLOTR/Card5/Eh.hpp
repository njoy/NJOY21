struct Eh {
  using Value_t = float;
  static std::string name(){ return "eh"; }
  static std::string description(){
    return
      "The eh argument specifies the upper bound for the energy (x) axis.\n\n"
      "Checks that eh has a greater value than el.";
  }
  static Value_t defaultValue( const Argument< El >& ){ return 1.0; }
  static bool verify( const Value_t v, 
                      const Argument< El >& el ){
    return ( v >= 0 and v > el.value );
  }
};
