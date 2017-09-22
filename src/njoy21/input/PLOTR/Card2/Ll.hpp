struct Ll {
  using Value_t = float;
  static std::string name(){ return "Ll"; }
  static std::string description(){
    return
      "The xll and yll arguments specify the displacement from the default\n"
      "location on the page that the plot appears.  By default, lower left\n"
      "corner of the plot (including axis labels) is 0.5 inches from the\n"
      "bottom edge of the page and 0.5 inches from the left edge of the page.\n"
      "The displacement specified by these arguments is in inches and\n"
      "defaults to 0.0 inches.  Negative and positive values are accepted.\n"
      "However, the value must be on the page, which has the dimensions\n"
      "8.5x11 inches.  The orientation is defined by the lori argument on\n"
      "Card 1.";
  }
  static Value_t defaultValue(const float){ return 0.0; }
  static bool verify( Value_t v , const float pgsize, const float marg = 0.5 ){
    return ( v <= pgsize+marg and v >= marg*-1.0 );
  }
};
