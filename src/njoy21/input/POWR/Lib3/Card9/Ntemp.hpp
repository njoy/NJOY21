struct Ntemp{
  using Value_t = int;
  static std::string name(){ return "ntemp"; }
  static std::string description(){
    return "The ntemp parameter specifies the number of temperatures on the\n"
           "old library for this time-dependent isotope.";
  }
  static bool verify( const Value_t ntemp ){
    return ntemp >= 0;
  }
};
