struct Isym {
  using Value_t = int;
  static std::string name(){ return "isym"; }
  static std::string description(){
    return
      "The isym argument specifies the symbol to be used.  The options are:\n\n"
      "    0 - square\n"
      "    1 - octagon\n"
      "    2 - triangle\n"
      "    3 - cross\n"
      "    4 - ex\n"
      "    5 - diamond\n"
      "    6 - inverted triangle\n"
      "    7 - exed square\n"
      "    8 - crossed ex\n"
      "    9 - crossed diamond\n"
      "   10 - crossed octagon\n"
      "   11 - double triangle\n"
      "   12 - crossed square\n"
      "   13 - exed octagon\n"
      "   14 - triangle and square\n"
      "   15 - filled circle\n"
      "   16 - open circle\n"
      "   17 - open square\n"
      "   18 - filled square\n\n"
      "   default = 0";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v < 19 and v >= 0 ); }
};
