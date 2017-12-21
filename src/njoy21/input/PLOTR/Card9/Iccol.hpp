struct Iccol {
  using Value_t = int;
  static std::string name(){ return "iccol"; }
  static std::string description(){
    return
      "The iccol argument specifies the color of the curve.  The options\n"
      "are:\n\n"
      "    0 - black\n"
      "    1 - red\n"
      "    2 - green\n"
      "    3 - blue\n"
      "    4 - magenta\n"
      "    5 - cyan\n"
      "    6 - brown\n"
      "    7 - purple\n"
      "    8 - orange\n\n"
      "The default value is 0 - black.";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v >= 0 and v < 9 ); }
};
