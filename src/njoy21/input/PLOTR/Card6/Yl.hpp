struct Yl {
  using Value_t = float;
  static std::string name(){ return "yl"; }
  static std::string description(){
    return
      "The yl argument specifies the lower bound for the y-axis.\n";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( Value_t v ){
    return ( v >= 0.0 );
  }
};
