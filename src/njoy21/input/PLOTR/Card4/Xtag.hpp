struct Xtag {
  using Value_t = float;
  static std::string name(){ return "xtag"; }
  static std::string description(){
    return
      "The xtag argument specifies the x-coordinate of the upper-left\n"
      "corner of the legend.\n\n"
      "The default will be to put the legend on the left edge of the plot.";
  }
  // defaultValue will be used by Card5 to set the default x-coordinate.
  static bool defaultValue(){ return true; }
  static bool verify( Value_t v ){
    return ( v >= 0 );
  }
};
