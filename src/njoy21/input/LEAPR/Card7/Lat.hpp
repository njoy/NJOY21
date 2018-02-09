struct Lat {
  using Value_t = int;
  static std::string name(){ return "lat"; }
  static std::string description(){
    return
      "The lat argument accepts an integer input of either 0 or 1, and is\n"
      "to control how the alpha and beta grids are spread out in the ENDF\n"
      "evaluation.\n"
      "\n"
      "In the ENDF thermal format, S(a,b) values for high temperatures are\n"
      "given on the same alpha and beta grids that are used for the base\n"
      "temperature. However, since alpha and beta are inversely proportional\n"
      "to temperature, only small alpha and beta values would be seen at\n"
      "high temperatures. The results for the higher values would normally\n"
      "be zero, which is a waste of space on the ENDF evaluation.\n"
      "\n"
      "To account for this, setting lat = 1 spreads alpha and beta values\n"
      "for higher temperatures out, thereby giving a more accurate\n"
      "representation, by scaling the alpha and beta values by 0.0253/tev,\n"
      "where tev is the temperature in eV. A value of lat = 0 will not alter\n"
      "the spread of alpha and beta values.\n"
      "\n"
      "lat must be either 0 or 1, and has a default value of 0.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& lat ){ return lat == 0 or lat == 1; }
};
