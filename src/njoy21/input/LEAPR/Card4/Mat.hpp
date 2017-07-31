struct Mat { 
  using Value_t = int;
  static std::string name(){ return "mat"; } 
  static std::string description(){
    return 
      "The mat input should be an integer with value in the range 1 - 99,\n"
      "inclusively, and is used to identify the desired compound.\n"
      "\n"
      "mat number assignments for compounds have the following structure:\n"
      "\n"
      "----------------------------------------\n"
      "| Hydrogen (except organics)    1 - 10 |\n"
      "| Deuterium                    11 - 20 |\n"
      "| Lithium                      21 - 25 |\n"
      "| Beryllium                    26 - 30 |\n"
      "| Carbon (including organics)  31 - 44 |\n"
      "| Oxygen                       45 - 50 |\n"
      "| Metals                       51 - 70 |\n"
      "| Fuels                        71 - 99 |\n"
      "----------------------------------------";
  }

  static bool verify( const Value_t v ){ return ( v < 100 and v > 0 ); }
};
