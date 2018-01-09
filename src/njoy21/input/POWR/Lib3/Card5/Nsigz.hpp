struct Nsigz{
  using Value_t = int;
  static std::string name(){ return "nsigz"; }
  static std::string description(){
    return "The nsigz parameter specifies the number of sigma zero values to\n"
           "process for this material.\n"
           "The default value is zero (0), specifying that all of the values\n"
           "found on the input tape should be processed.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t nsigz ){
    return nsigz >= 0;
  }
};
