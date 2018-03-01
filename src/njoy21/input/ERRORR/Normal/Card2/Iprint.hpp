struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }
  static std::string description(){
    return "The iprint parameter specifies the print option.\n\n"
           " 0 -- minimal printing\n"
           " 1 -- maximum printing ( default )";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t iprint ){
    return ( iprint == 0 or iprint == 1 );
  }
};
