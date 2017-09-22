struct Facty {
  using Value_t = float;
  static std::string name(){ return "facty"; }
  static std::string description(){
    return
      "The facty argument specifies the factor by which the current curve\n"
      "is scaled to the y-axis.  As the y-axis is always cross section in\n"
      "these plots, it corresponds to 1 barn for the curve occupies facty\n"
      "barn worth of space on the y-axis.\n\n"
      "For example, if facty is set to 0.5, every 1 barn worth of the curve\n"
      "takes up 0.5 barn worth of the axis, allowing for twice as much of the\n"
      "curve to be displayed.\n"
      "Likewise, if facty is set to a value greater than 1, less of the curve\n"
      "will fit on the plot.\n\n"
      "This does not have an affect on the values displayed on the y-axis,\n"
      "so the axis will no longer be relevant for the curve except as an\n"
      "indirect indication of how many barns apart two points are.";
  }
  static Value_t defaultValue(){ return 1.0; }
  static bool verify( Value_t v ){
    return ( v > 0.0 );
  }
};
