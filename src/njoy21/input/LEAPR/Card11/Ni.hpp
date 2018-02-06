struct Ni {
  using Value_t = int;
  static std::string name(){ return "ni"; }
  static std::string description(){
    return
      "The ni argument is the number of points desired for the S(a,b) grid.\n"
      "ni must be an integer input greater than zero.";
  }
  static bool verify( const Value_t& ni ){ return ni > 0; }
};
