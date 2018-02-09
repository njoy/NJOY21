struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }

  static std::string description(){
    return
      "The iprint argument controls the print options, and can take a value\n"
      "of either 0, 1, or 2. These values correspond to printing a minimum,\n"
      "moderate, and maximum amount of output.\n"
      "\n"
      "iprint has a default value of 1.";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( Value_t i ){ return i == 0 or i == 1 or i == 2; } 
};

