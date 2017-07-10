struct Mtref {
  using Value_t = int;
  static std::string name(){ return "mtref"; }

  static std::string description(){
    return
      "mt values are labels for endf sections, where the sections are usually\n"
      "used to hold different reactions.\n"
      "\n"
      "The mtref argument is the mt for the desired inelastic option. These\n"
      "mt values must be between 221 and 250, inclusively.";
    }

  static bool verify( Value_t i ){ return 221 <= i and i <= 250; } 
};

