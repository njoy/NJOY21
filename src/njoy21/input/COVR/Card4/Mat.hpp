struct Mat : argument::common::Matd {
  static std::string name(){ return "mat"; }
  static std::string description(){
    return
      "The mat input is the material id for the desired material on the\n"
      "endf tape, which was specified on the card1 input parameter 'nendf'.\n"
      "\n"
      "Material id numbers must be positive integers with values less than\n"
      "10,000. For the mat input in particular, however, a value of 0 is\n"
      "valid, as that signifies that no nendf tape was provided.";
  }
};
