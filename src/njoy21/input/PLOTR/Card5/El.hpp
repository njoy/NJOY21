struct El {
  using Value_t = float;
  static std::string name(){ return "el"; }
  static std::string description(){
    return
      "The el argument specifies the lower bound for the energy (x) axis.\n";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( Value_t v ){
    return ( v >= 0 );
  }
};
