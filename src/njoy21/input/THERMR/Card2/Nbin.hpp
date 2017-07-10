struct Nbin {
  using Value_t = int;
  static std::string name(){ return "nbin"; }

  static std::string description(){
    return
      "nbin is the number of equi-probable scattering angles available. For\n"
      "example, calculations of thermal cross sections for hydrogen in water\n"
      "will result in 8 equi-probable scattering angles, which means that \n"
      "there will be 8 discrete secondary consines given for each energy\n"
      "change.\n"
      "\n"
      "nbin must be a positive integer.";
    }

  static bool verify( Value_t i ){ return 0 < i; } 
};

