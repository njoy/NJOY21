struct Wr {
  using Value_t = float;
  static std::string name(){ return "wr"; }
  static std::string description(){
    return
      "The wr argument specifies the rotation of the window for this plot.\n"
      "wr combines the ww and wh values using the pythagoream theorem to\n"
      "determine the distance from the point defined by xll and yll to the\n"
      "opposite corner of the window.  The direction from the (xll,yll)\n"
      "corner to the opposite corner is defined by wr as degrees\n"
      "counter-clockwise from the positive x direction.  The plot maintains\n"
      "the height and width defined by wh and ww, respectively, but it\n"
      "will only be visible inside of the window.  As such wr should usually\n"
      "be a multiple of 90 in order for the window shape to match the plot.\n"
      "Any values that are multiples of 45 but not 90 will result in the plot\n"
      "being 1-dimensional and, therefore, not displayed.\n\n"
      "The default value is 0.0.  All floats -90.0 or greater are accepted.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( Value_t v ){ return ( v >= -90.0 ); }
};
