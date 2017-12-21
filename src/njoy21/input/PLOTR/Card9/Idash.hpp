struct Idash {
  using Value_t = int;
  static std::string name(){ return "idash"; }
  static std::string description(){
    return
      "The idash argument specifies the type of line to plot.  The options\n"
      "are:\n\n"
      "    0 - solid\n"
      "    1 - dashed\n"
      "    2 - chain dash\n"
      "    3 - chain dot\n"
      "    4 - dot\n\n"
      "The default value is 0.";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v >= 0 and v < 5 ); }
};
