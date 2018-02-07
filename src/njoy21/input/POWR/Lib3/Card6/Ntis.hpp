struct Ntis{
  using Value_t = int;
  static std::string name(){ return "ntis"; }
  static std::string description(){
    return "The ntis parameter specifies the number of time-dependent\n"
           "isotopes.";
  }
  static bool verify( const Value_t ntis ){
    return ntis >= 0;
  }
};
