struct Nsgz{
  using Value_t = int;

  static std::string name(){ return "nsgz"; }
  static std::string description(){
    return "The nsgz parameter specifies the number of sigma zeroes to\n"
           "process for this material.  The default is zero (0) indicating\n"
           "that all the sigam zeroes found on the input tape should be\n"
           "processed.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t nsgz ){
    return nsgz >= 0;
  }
};
