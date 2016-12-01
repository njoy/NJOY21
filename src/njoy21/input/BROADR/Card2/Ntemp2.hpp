struct Ntemp2 {
  using Value_t = int;
  static std::string name(){ return "ntemp2"; }
  static std::string description(){
    return
      "The ntemp2 argument specifies the number of final temperatures\n"
      "desired for the doppler broadening operation. This argument defaults\n"
      "to a value of 1 and must be a positive integer (obviously)";
  }

  static int defaultValue(){ return 1; }
  static bool verify( Value_t v ){ return v > 0; }
};
