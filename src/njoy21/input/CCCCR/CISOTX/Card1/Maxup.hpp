struct Maxup {
  using Value_t = int;
  static std::string name(){ return "maxup"; }
  static std::string description(){
    return "The maxup parameter specifies the maximum number of upscatter\n"
           "groups.  This value is always zero.";
  }
  static bool verify( const Value_t maxup ){
    return maxup == 0;
  }
};
