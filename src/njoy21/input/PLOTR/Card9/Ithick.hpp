struct Ithick {
  using Value_t = int;
  static std::string name(){ return "ithick"; }
  static std::string description(){
    return
      "The ithick argument specifies the thickness of the curve.\n\n"
      "The options are 0 for an invisible line, if generating a shaded area\n"
      "plot, and 1 for a visible line.  The default value is 1.";
  }
  static int defaultValue(){ return 1; }
  static bool verify( Value_t v ){ return ( v == 0 or v == 1 ); }
};
