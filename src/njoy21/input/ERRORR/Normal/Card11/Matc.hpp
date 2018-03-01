struct Matc : argument::common::Matd {
  static std::string name(){ return "matc"; }
  static std::string description(){
    return "The matc parameter specifies the material as part of the\n"
           "material/MT combination that will replace the combination\n"
           "specified earlier in this card.";
  }
};
