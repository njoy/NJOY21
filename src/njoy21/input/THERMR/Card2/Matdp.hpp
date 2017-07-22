struct Matdp : argument::common::Matd {
  static std::string name(){ return "matdp"; }
  static std::string description(){
    return
      "The matdp input is the material id for the desired material on the\n"
      "pendf tape. The pendf tape was specified on the card1 input parameter\n"
      "'nin'.\n"
      "\n"
      "Material id numbers must be positive integers with values less than\n"
      "10,000.";
  }
};
