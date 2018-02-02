struct Ileg {
  using Value_t = int;
  static std::string name(){ return "ileg"; }
  static std::string description(){
    return
      "The ileg argument specifies the options for producing a legend.\n\n"
      "There are 3 options:\n"
      "    0 - none\n"
      "    1 - write a legend block with upper left corner at xtag,ytag,\n"
      "        specified by the following two values\n"
      "    2 - use tag labels on each curve with a vector from the tag to\n"
      "        the curve\n\n"
      "The default value is 0 - none.\n";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v < 3 and v >= 0 ); }
};
