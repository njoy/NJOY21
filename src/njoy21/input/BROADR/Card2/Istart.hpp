struct Istart {
  using Value_t = int;
  static std::string name(){ return "istart"; }
  static std::string description(){
    return
      "The istart argument is an optional integer argument that acts as a boolean\n"
      "flag. As such, only values of zero or one are permitted. When unspecified\n"
      "this argument defaults to zero.\n"
      "\n"
      "Then istart value is one, all temperatures which exist on the input PENDF\n"
      "tape are copied to the output tape (in addition to any temperatures\n"
      "specified in BROADR command). Additional final temperatures are added\n"
      "by starting with the data at the BROADR card2 temp1 argument.";
  }

  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return (v == 0) or (v == 1); }
};
