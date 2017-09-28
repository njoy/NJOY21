struct Xtag {
  using Value_t = float;
  static std::string name(){ return "xtag"; }
  static std::string description(){
    return
      "The xtag argument specifies the x position of the tag title.\n";
  }
  static bool verify( Value_t v ){
    return ( v >= 0.0 );
  }
};
