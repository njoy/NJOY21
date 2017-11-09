struct Yv {
  using Value_t = double;
  static std::string name(){ return "yv"; }
  static std::string description(){
    return
      "The yv argument specifies the y position of the view point for 3-D\n"
      "plots.\n\n"
      "The default value is -15.0.";
  }
  static Value_t defaultValue(){ return -15.0; }
};
