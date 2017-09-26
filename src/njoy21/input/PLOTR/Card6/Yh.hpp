struct Yh {
  using Value_t = float;
  static std::string name(){ return "yh"; }
  static std::string description(){
    return
      "The yh argument specifies the upper bound for the y-axis.\n\n"
      "Checks that yh has a greater value than yl.";
  }
  static Value_t defaultValue( const Argument< Yl >& ){ return 1.0; }
  static bool verify( const Value_t v, 
                      const Argument< Yl >& yl ){
    return ( v >= 0.0 and v > yl.value );
  }
};
