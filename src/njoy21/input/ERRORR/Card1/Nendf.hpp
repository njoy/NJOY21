struct Nendf : argument::common::Nin {
  static std::string name(){ return "nin"; }
  static std::string description(){
    return "The nin parameter specifies the unit for the endf tape.";
  }
};
