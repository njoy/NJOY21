struct Iprint{
  using Value_t = int;

  static std::string name(){ return "iprint"; }
  static std::string description(){
    return "The iprint parameter specifies the print option.\n\n"
           " 0 = minimum (default)\n 1 = maximum\n";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t iprint ){
    return ( iprint == 0 or iprint == 1 );
  }
};
