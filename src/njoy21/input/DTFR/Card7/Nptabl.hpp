struct Nptabl {
  using Value_t = int;
  static std::string name(){ return "nptabl"; }

  static std::string description(){
    return
      "Nptabl is the number of photon production tables, and is usually\n"
      "equal to zero (none) or one.\n"
      "\n"
      "Nptabl must be a non-negative integer.";
  }
  
  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ){ return 0 <= i; } 
};

