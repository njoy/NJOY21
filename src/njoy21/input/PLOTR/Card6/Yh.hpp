struct Yh {
  using Value_t = double;
  static std::string name(){ return "yh"; }
  static std::string description(){
    return
      "The yh argument specifies the upper bound for the y-axis.\n\n"
      "Checks that yh has a greater value than, or equal to, yl.\n\n"
      "If the y-scale is logarithmic, there is an imposed limit of 8 decades\n"
      "that the axis can span.  If a value greater than that is provided,\n"
      "VIEWR will cut off the lower y-values on the plot until 8 decades\n"
      "remain.";
  }
  static Value_t defaultValue( const Value_t yl ){
    return yl;
  }
  static bool verify( Value_t v, const Value_t yl ){
    return ( v >= yl );
  }
};
