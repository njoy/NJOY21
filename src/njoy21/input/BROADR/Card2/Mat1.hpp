struct Mat1 : public argument::common::Matd {
  using Value_t = argument::common::Matd::Value_t;
  static std::string name(){ return "mat1"; }
  static std::string description(){
    return
      "The mat1 argument is an integer corresponding to an ENDF material\n"
      "identification number (often referred to as a MAT number) and refers\n"
      "to the material on the PENDF tape (specified by the card1 nin argument)\n"
      "to be broadened and thinned.\n"
      "\n"
      "MAT number correspondence varies widely between ENDF format revisions.\n"
      "as a result, verification is minimal; the input value is required to be\n"
      "a positive value and less than 10000.";
  }
  
  using argument::common::Matd::verify;
};
