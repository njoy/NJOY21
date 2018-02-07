struct Ntemp{
  using Value_t = int;
  static std::string name(){ return "ntemp"; }
  static std::string description(){
    return "The ntemp parameter specifies the number of temperatures to\n"
           "process for this material.\n"
           "The default value is 0, specifying that all materials found on\n"
           "the input tape.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t ntemp ){ return ntemp >= 0; }
};
