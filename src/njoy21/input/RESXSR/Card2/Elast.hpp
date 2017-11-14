struct Elast {
  using Value_t = double;
  static std::string name(){ return "elast"; }
  static std::string description(){
    return "Upper energy limit in eV.  Must be greater than efirst.";
  }
  static bool verify( const Value_t el, const Value_t ef ){
    return el > ef;
  }
};
