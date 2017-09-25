struct Jtype {
  using Value_t = int;
  static std::string name(){ return "jtype"; }
  static std::string description(){
    return
      "The jtype argument specifies the scale for the secondary axes\n"
      "(alternate y-axis or z-axis).\n"
      "\nThere are 3 options:\n"
      "    0 - none\n"
      "    1 - linear\n"
      "    2 - log\n"
      "The default value is 0 - none.\n";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v < 3 and v >= 0 ); }
};
