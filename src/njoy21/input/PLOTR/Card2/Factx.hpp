struct Factx {
  using Value_t = double;
  static std::string name(){ return "factx"; }
  static std::string description(){
    return
      "The factx argument specifies the factor by which the current curve\n"
      "is scaled to the x-axis.  As the x-axis is always energy in these\n"
      "plots, it corresponds to 1 eV for the curve occupies factx eV worth\n"
      "of space on the x-axis.\n\n"
      "For example, if factx is set to 0.5, every 1 eV worth of the curve\n"
      "takes up 0.5 eV worth of the axis, allowing for twice as much of the\n"
      "curve to be displayed.\n"
      "Likewise, if factx is set to a value greater than 1, less of the curve\n"
      "will fit on the plot.\n\n"
      "This does not have an affect on the values displayed on the x-axis,\n"
      "so the axis will no longer be relevant for the curve except as an\n"
      "indirect indication of how many eV apart two points are.";
  }
  static Value_t defaultValue(){ return 1.0; }
  static bool verify( Value_t v ){
    return ( v > 0.0 );
  }
};
