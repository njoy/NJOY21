struct Icon {
  using Value_t = int;
  static std::string name(){ return "icon"; }
  static std::string description(){
    return
      "The icon argument specifies the symbol and connection option for the\n"
      "plot.  The default value is 0, which corresponds to no symbols and\n"
      "the points are all connected.  If the value is a positive integer (i),\n"
      "the points are connected and there are symbols every i points.  If\n"
      "the value is a negative integer (-i), the points are not connected\n"
      "and there are symbols every i points.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t ){ return true; }
};
