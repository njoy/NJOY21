struct Mprint {
  using Value_t = int;
  static std::string name(){ return "mprint"; }
  static std::string description(){
    return "The mprint parameter specifies the print option for group\n"
           "averaging.\n\n"
           " 0 -- minimal ( default )\n"
           " 1 -- maximal";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t mprint ){
    return ( mprint == 0 or mprint == 1 );
  }
};
