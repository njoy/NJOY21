struct Nholl {
  using Value_t = unsigned int;
  static std::string name(){ return "nholl"; }
  static std::string description(){
    return "The number of lines of descriptive comments.\n"
           "This will be used to determine the number of times card 4 will be\n"
           "read.  The maximum allowed number of lines is 10.";
  }
// Value is based on resxsr.f90: 204 and 241-245.
  static bool verify( const Value_t nh ){
    return nh < 11;
  }
};
