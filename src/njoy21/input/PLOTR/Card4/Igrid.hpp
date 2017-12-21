struct Igrid {
  using Value_t = int;
  static std::string name(){ return "igrid"; }
  static std::string description(){
    return
      "The igrid argument specifies the pattern for grid and tic marks.\n\n"
      "There are 4 options:\n"
      "    0 - no grid lines or tic marks\n"
      "    1 - grid lines\n"
      "    2 - tic marks on the outside\n"
      "    3 - tic marks on the inside\n"
      "The default value is 2 - tic marks on the outside.\n";
  }
  static int defaultValue(){ return 2; }
  static bool verify( Value_t v ){ return ( v < 4 and v >= 0 ); }
};
