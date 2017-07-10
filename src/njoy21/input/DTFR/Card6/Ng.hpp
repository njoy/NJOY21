struct Ng {
  using Value_t = int;
  static std::string name(){ return "ng"; }

  static std::string description(){
    return
      "ng is the number of neutron groups, and this value must agree with\n"
      "the number on the input tape from GROUPR.\n"
      "\n"
      "ng is required to have a value > 0, and has a default value of 30.";
  }

  static Value_t defaultValue(){ return 30; }
  static bool verify( Value_t i ){ return 0 < i; } 
};

