struct Ishade {
  using Value_t = int;
  static std::string name(){ return "ishade"; }
  static std::string description(){
    return
      "The ishade argument specifies the shade pattern.  The options are:\n\n"
      "    0 - none\n"
      " 1-10 - 10% to 100% gray\n"
      "11-20 - 45 degree right hatching\n"
      "21-30 - 45 degree left hatching\n"
      "31-40 - 45 degree cross hatching\n"
      "41-50 - shades of green\n"
      "51-60 - shades of red\n"
      "61-70 - shades of brown\n"
      "71-80 - shades of blue\n\n"
      "The default value is 0 - none.";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v >= 0 and v < 81 ); }
};
