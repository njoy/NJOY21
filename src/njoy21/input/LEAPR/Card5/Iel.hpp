struct Iel {
  using Value_t = int;
  static std::string name(){ return "iel"; }
  static std::string description(){
    return
      "The iel argument is the coherent elastic option, which takes an\n"
      "integer input between 0 and 6, inclusively. Normally, a value of\n"
      "zero is appropriate, except for solid moderators. Six crystalline\n"
      "materials are recognized, which are shown below (along with their\n"
      "corresponding iel value).\n"
      "\n"
      "----------------------\n"
      "| 0 none (default)   |\n"
      "| 1 graphite         |\n"
      "| 2 beryllium        |\n"
      "| 3 beryllium oxide  |\n"
      "| 4 FCC aluminum     |\n"
      "| 5 lead             |\n"
      "| 6 BCC iron         |\n"
      "----------------------\n"
      "\n"
      "iel has a default value of 0";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& iel ){ return iel >= 0 and iel <= 6; }
};
