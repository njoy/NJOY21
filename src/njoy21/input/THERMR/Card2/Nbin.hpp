struct Nbin {
  using Value_t = int;
  static std::string name(){ return "nbin"; }

  static std::string description(){
    return
      "nbin is the number of equi-probable scattering angles available. So\n"
      "the scattering distribution is divided into nbin different bins,\n"
      "where the probability of picking each bin is equivalent.\n"
      "\n"
      "nbin must be a positive integer.";
    }

  static bool verify( Value_t i ){ return 0 < i; } 
};

