struct Iin {
  using Value_t = int;
  static std::string name(){ return "iin"; }

  static std::string description(){
    return
      "iin is the inelastic scattering option, where a value of 0 indicates\n"
      "that no inelastic scattering will be considered, a value of 1\n"
      "indicates that the material will be considered as a free gas, and\n"
      "a value of 2 indicates that s(a,b) will be read in and the matrix \n"
      "will be computed.";
  }

  static bool verify( Value_t i ){ return i == 0 or i == 1 or i == 2; } 
};

