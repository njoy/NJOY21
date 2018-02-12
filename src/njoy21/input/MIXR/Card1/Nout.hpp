struct Nout : argument::common::Nin {
  static std::string name(){ return "nout"; }
  static std::string description(){
    return "The nout parameter specifies the output unit for the mixed cross\n"
           "sections.  The allowable values are between -99 and -20,\n"
           "inclusively, and 20 and 99, inclusively.";
  }
};
