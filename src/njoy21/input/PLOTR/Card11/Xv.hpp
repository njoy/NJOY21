struct Xv {
  using Value_t = double;
  static std::string name(){ return "xv"; }
  static std::string description(){
    return
      "The xv argument specifies the x position of the view point for 3-D\n"
      "plots.\n\n"
      "The default value is 15.0.";
  }
  static Value_t defaultValue(){ return 15.0; }
};
