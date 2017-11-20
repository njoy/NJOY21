struct X3 {
  using Value_t = double;
  static std::string name(){ return "x3"; }
  static std::string description(){
    return
      "The x3 argument specifies the length of the box volume along the\n"
      "x-axis for a 3-D plot.\n\n"
      "The default value is 2.5.\n\n"
      "Setting this value or y3 to a negative value will flip the order\n"
      "of the axis on that side of the work box.";
  }
  static Value_t defaultValue(){ return 2.5; }
  static bool verify( Value_t v ){ return v != 0.0; }
};
