struct Iplot {
  using Value_t = int;
  static std::string name(){ return "iplot"; }
  static std::string description(){
    return
      "The iplot argument specifies the plot index for the current plot.\n"
      "It also signals if the plot is on the same graph, a new graph on the\n"
      "same page, a new graph on a new page, or a new graph on the same plot,\n"
      "but using a new y-axis.\n\n"
      "The options are:\n"
      "    99 - terminate the plotting job\n"
      "    1  - new axes, new page\n"
      "   -1  - new axes, existing page\n"
      "    n  - nth additional plot on the existing axes\n"
      "   -n  - start a new set of curves using the alternate y-axis\n\n"
      "The default option is: '1 - new axes, new page'.";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( Value_t v ){ return ( std::abs(v) < 100 and v != 0 ); }
};
