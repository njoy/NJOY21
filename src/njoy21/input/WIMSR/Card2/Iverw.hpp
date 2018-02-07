struct Iverw {
  using Value_t = int;
  static std::string name(){ return "iverw"; }
  static std::string description(){
    return "The iverw paramter specifies the version of WIMS that is\n"
           "targeted.  The default value is 4, for WIMS-D.  A value of 5\n"
           "is used for WIMS-E.";
  }
  static Value_t defaultValue(){ return 4; }
  static bool verify( const Value_t iverw ){
    return iverw == 4 or iverw == 5;
  }
};
