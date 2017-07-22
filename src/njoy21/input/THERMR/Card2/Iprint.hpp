struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }

  static std::string description(){
    return
      "The iprint argument controls the print options, and can take a value\n"
      "of either 0, 1, or 2. An iprint value of 0 will print the minimum\n"
      "amount of output, 1 will print the maximum, and 2 will print the\n"
      "maximum, as well as intermediate results.\n"
      "\n"
      "iprint has a default value of 0.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ){ return i == 0 or i == 1 or i == 2; } 
};

