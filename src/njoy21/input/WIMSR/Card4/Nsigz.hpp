struct Nsigz {
  using Value_t = int;
  static std::string name(){ return "nsigz"; }
  static std::string description(){
    return "The nsigz parameter is the number of sigma zeroes to process for\n"
           "this material.\n\n"
           "A value of zero (0) means that the values are found on the input\n"
           "tape.";
  }
  static bool verify( const Value_t nsigz ){
    return ( nsigz >= 0 );
  }
};
