struct Nunx {
  using Value_t = int;
  static std::string name(){ return "nunx"; }

  static std::string description() {
    return
        "The nunx parameter specifies the number of energy points desired. If\n"
        "all of the energy points are desired, simply enter a value of 0, \n"
        "which is the default.";
  }

  static int defaultValue(){ return 0; }
  static bool verify( Value_t n ){ return n >= 0; }
};
