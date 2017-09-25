struct Itype {
  using Value_t = int;
  static std::string name(){ return "itype"; }
  static std::string description(){
    return
      "The itype argument specifies the scale for the primary axes (x and\n"
      "primary y).\n\n"
      "There are 4 options:\n"
      "    1 - linear x - linear y\n"
      "    2 - linear x - log y\n"
      "    3 - log x - linear y\n"
      "    4 - log x - log y\n\n"
      "The default value is 4 - log x - log y.\n";
  }
  static int defaultValue(){ return 4; }
  static bool verify( Value_t v ){ return ( std::abs(v) < 5 and v != 0 ); }
};
