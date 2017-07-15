struct Natom {
  using Value_t = int;
  static std::string name(){ return "natom"; }

  static std::string description(){
    return
      "natom is the number of principle atoms in the desired material. For\n"
      "instance, in considering the thermal cross sections for hydrogen in\n"
      "water, natom is set to 2 because a water molecule contains two\n"
      "hydrogen atoms.\n"
      "\n"
      "The natom input must be a positive integer.";
    }

  static bool verify( Value_t i ){ return 1 <= i; } 
};

