struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }
  static std::string description(){
    return "The iprint parameter specifies how much detail will be printed\n"
           "on the output listing.\n\n"
           " 0 = minimal (default)\n"
           " 1 = regular\n"
           " 2 = regular as well as intermediate results";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t iprint ){
    return iprint == 0 or iprint == 1 or iprint == 2;
  }
};
