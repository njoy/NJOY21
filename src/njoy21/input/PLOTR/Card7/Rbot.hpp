struct Rbot {
  using Value_t = float;
  static std::string name(){ return "rbot"; }
  static std::string description(){
    return
      "The rbot argument specifies the lower bound for the alternate y-axis\n"
      "or the z-axis.";
  }
  static Value_t defaultValue( const int jtype ){
    if( jtype == 2 ) return 1.0e-07;
    return 0.0;
  }
  static bool verify( Value_t v, const int jtype ){
    if( jtype == 2 ) return ( v > 0 );
    return true;
  }
};
