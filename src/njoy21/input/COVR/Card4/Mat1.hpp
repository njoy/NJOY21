struct Mat1 : argument::common::Matd {
  static std::string name(){ return "mat1"; }
  static std::string description(){
    return
      "If mat1 is different from mat, COVR will expect to find separate \n"
      "materials (produced by separate ERRORR runs) for both mat and mat1 on\n"
      "nin. The mat numbers must occur on nin in ascending order.\n"
      "\n"
      "Material id numbers must be positive integers with values less than\n"
      "10,000. However, a value of 0 is valid, and signifies that no nendf\n"
      "tape was provided.";
  }
  static Value_t defaultValue(){ return 0; }
};
