struct Jpos {
  using Value_t = int;
  static std::string name(){ return "jpos"; }

  static std::string description(){
    return
      "jpos is the first value in any of the Card5 triplets. Jpos represents\n"
      "the position of the edit quantity. Therefore, jpos must be an integer\n"
      "greater than or equal to zero."; 
  }

  static bool verify( Value_t i ){ return 0 <= i; } 
};

