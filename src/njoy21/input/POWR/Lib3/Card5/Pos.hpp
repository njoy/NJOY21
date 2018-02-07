struct Pos{
  using Value_t = int;
  static std::string name(){ return "pos"; }
  static std::string description(){
    return "The pos parameter specifies the position of the isotope in the\n"
           "cpmlib.";
  }
  static bool verify( const Value_t pos ){
    return pos >= 0;
  }
};
