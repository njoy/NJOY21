struct Z3 {
  using Value_t = float;
  static std::string name(){ return "z3"; }
  static std::string description(){
    return
      "The z3 argument specifies the length of the box volume along the\n"
      "z-axis for a 3-D plot.\n\n"
      "The default value is 2.5.";
  }
  static Value_t defaultValue(){ return 2.5; }
  static bool verify( Value_t ){ return true; }
};
