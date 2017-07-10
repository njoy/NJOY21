struct Iform {
  using Value_t = int;
  static std::string name(){ return "iform"; }

  static std::string description(){
    return
      "iform is the output format option for inelastic distributions, and\n"
      "can take a value of either 0 or 1. A value of 0 signifies E-E'-mu\n"
      "ordering (MF6 special), while a value of 1 signifies E-mu-E' ordering\n"
      "(MF6/Law7).";
  }

  static bool verify( Value_t i ){ return i == 0 or i == 1; } 
};

