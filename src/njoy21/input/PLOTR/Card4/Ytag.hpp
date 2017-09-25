struct Ytag {
  using Value_t = float;
  static std::string name(){ return "ytag"; }
  static std::string description(){
    return
      "The ytag argument specifies the y-coordinate of the upper-left\n"
      "corner of the legend.\n\n"
      "The default will be to put the legend at the top of the plot.";
  }
  // defaultValue will be used by Card6 to set the default y-coordinate.
  static bool defaultValue(){ return true; }
  static bool verify( Value_t v ){
    return ( v >= 0 );
  }
};
