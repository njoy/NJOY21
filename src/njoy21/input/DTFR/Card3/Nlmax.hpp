struct Nlmax {
  using Value_t = int;
  static std::string name(){ return "nlmax"; }

  static std::string description(){
    return
      "nlmax is the number of Legendre neutron tables desired. That is,\n"
      "it would be 4 for a P_3 set. nlmax must be > 0.";
  }

  static bool verify( Value_t i ){ return 0 < i; } 
};

