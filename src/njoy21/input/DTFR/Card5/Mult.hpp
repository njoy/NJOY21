struct Mult {
  using Value_t = int;
  static std::string name(){ return "mult"; }

  static std::string description(){
    return
      "Mult is the third value in the Card5 triplet, and represents the\n"
      "multiplicity to be used when adding the Mt.\n"
      "\n"
      "Mult must be an integer greater than or equal to zero."; 
  }

  static bool verify( Value_t i ){ return 0 <= i; } 
};

