struct Ntemp {
  using Value_t = int;
  static std::string name(){ return "ntemp"; }
  static std::string description(){
    return
      "The ntemp argument specifies the number of final temperatures\n"
      "desired for the doppler broadening operation. This argument defaults\n"
      "to a value of 1 and must be a positive integer (obviously)";
  }

  static int defaultValue(){ return 1; }
  static bool verify( Value_t v ){ return v > 0; }
};
