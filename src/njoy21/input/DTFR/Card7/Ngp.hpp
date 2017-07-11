struct Ngp {
  using Value_t = int;
  static std::string name(){ return "ngp"; }

  static std::string description(){
    return
      "ngp is the number of gamma groups, and this value must agree with\n"
      "the the photon group structure used in GROUPR.\n"
      "\n"
      "ngp is required to be some non-negative integer, and has a default\n."
      "value of 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ){ return 0 <= i; } 
};

