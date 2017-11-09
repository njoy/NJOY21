struct Zv {
  using Value_t = double;
  static std::string name(){ return "zv"; }
  static std::string description(){
    return
      "The zv argument specifies the z position of the view point for 3-D\n"
      "plots.\n\n"
      "The default value is 15.0.";
  }
  static Value_t defaultValue(){ return 15.0; }
};
