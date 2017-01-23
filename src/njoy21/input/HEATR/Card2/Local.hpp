struct Local {
  using Value_t = int;
  static std::string name(){ return "local"; }
  static std::string description(){
    return
      "The local argument is an optional integer argument that acts as a\n"
      "boolean flag. As such, only values of zero or one are permitted. When\n"
      "unspecified this argument defaults to zero.\n"
      "\n"
      "The local flag denotes whether energy from secondary photons should be\n"
      "deposited locally, or be permitted to be transported. A value of zero \n"
      "corresponds to the former, while a value of 1 corresponds to the latter";
  }

  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return (v == 0) or (v == 1); }
};
