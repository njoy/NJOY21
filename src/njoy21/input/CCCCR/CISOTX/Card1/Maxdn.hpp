struct Maxdn {
  using Value_t = int;
  static std::string name(){ return "maxdn"; }
  static std::string description(){
    return "The maxdn parameter specifies the maximum number of downscatter\n"
           "groups.  The value must be between zero and ngroup.";
  }
  static bool verify( const Value_t maxdn, const int ngroup ){
    return ( maxdn <= ngroup and maxdn >= 0 );
  }
};
