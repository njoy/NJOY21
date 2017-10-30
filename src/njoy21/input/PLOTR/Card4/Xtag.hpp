struct Xtag {
  using Value_t = optional< double >;
  static std::string name(){ return "xtag"; }
  static std::string description(){
    return
      "The xtag argument specifies the x-coordinate of the upper-left\n"
      "corner of the legend.\n\n"
      "The default will be to put the legend on the left edge of the plot.";
  }
  // defaultVal will be used by Card5 to set the default x-coordinate.
  static Value_t defaultValue(){ return std::nullopt; }
  static bool verify( const Value_t& v ){ return (not v) or (*v >= 0.0 ); }
};
