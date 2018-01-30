struct Ntemp {
  using Value_t = int;
  static std::string name(){ return "ntemp"; }
  static std::string description(){
    return "The ntemp parameter is the number of temperatures to process\n"
           "for this material in the thermal energy range.\n\n"
           "A value of zero (0) means that all of the temperatures are found\n"
           "on the input tape.";
  }
  static bool verify( const Value_t ntemp ){
    return ntemp >= 0;
  }
};
