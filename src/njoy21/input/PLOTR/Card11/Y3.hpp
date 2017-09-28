struct Y3 {
  using Value_t = float;
  static std::string name(){ return "y3"; }
  static std::string description(){
    return
      "The y3 argument specifies the length of the box volume along the\n"
      "y-axis for a 3-D plot.\n\n"
      "The default value is 6.5.\n\n"
      "Setting this value or x3 to a negative value will flip the order\n"
      "of the axis on that side of the work box.";
  }
  static Value_t defaultValue(){ return 6.5; }
  static bool verify( Value_t ){ return true; }
};
