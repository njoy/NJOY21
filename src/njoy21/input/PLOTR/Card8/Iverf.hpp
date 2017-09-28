struct Iverf {
  using Value_t = int;
  static std::string name(){ return "iverf"; }
  static std::string description(){
    return
      "The iverf argument specifies the version of the endf tape.\n"
      "To read data off of an input file, set this to 0 (default).\n"
      "For gendf data, set this to 1.\n"
      "Otherwise, set this to the version of the endf tape from which the\n"
      "data will be collected.";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v < 9 and v >= 0 ); }
};
