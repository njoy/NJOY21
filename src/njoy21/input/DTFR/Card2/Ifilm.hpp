struct Ifilm {
  using Value_t = int;
  static std::string name(){ return "ifilm"; }

  static std::string description(){
    return
      "The ifilm value is film control, which can be used to suppress\n"
      "plotting, or to request plots with either 1 or 4 graphs per frame.\n"
      "A value of 0 corresponds to plots suppressed, a value of 1\n"
      "corresponds to 1 plot per frame, and a value of 2 corresponds to\n"
      "4 plots per frame. No other values outside of 0, 1, and 2 are\n"
      "permitted.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ){ return i == 0 || i == 1 || i == 2; }
};

