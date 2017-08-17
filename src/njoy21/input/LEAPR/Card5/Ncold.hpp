struct Ncold {
  using Value_t = int;
  static std::string name(){ return "ncold"; }
  static std::string description(){
    return
      "The ncold argument is the cold hydrogren option, which takes an\n"
      "integer input between 0 and 4, inclusively. ncold is normally set to\n"
      "zero, except when a liquid hydrogen or deuterium calculation is\n"
      "desired.\n"
      "\n"
      "----------------------\n"
      "| 0 none (default)   |\n"
      "| 1 ortho hydrogen   |\n"
      "| 2 para hydrogen    |\n"
      "| 3 ortho deuterium  |\n"
      "| 4 para deuterium   |\n"
      "----------------------\n"
      "\n"
      "ncold has a default value of 0";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& n ){ return n >= 0 and n <= 4; }
};
