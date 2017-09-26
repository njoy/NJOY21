struct Rbot {
  using Value_t = float;
  static std::string name(){ return "rbot"; }
  static std::string description(){
    return
      "The rbot argument specifies the lower bound for the alternate y-axis\n"
      "or the z-axis.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( Value_t v ){
    return ( v >= 0.0 );
  }
};
