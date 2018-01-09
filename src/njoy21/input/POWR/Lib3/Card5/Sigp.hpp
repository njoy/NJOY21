struct Sigp{
  using Value_t = double;
  static std::string name(){ return "sigp"; }
  static std::string description(){
    return "The sigp parameter specifies the potential cross section from\n"
           "endf.";
  }
  static bool verify( const Value_t sigp ){
    return sigp >= 0.0;
  }
};
