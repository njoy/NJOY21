struct Lprint{
  using Value_t = int;
  static std::string name(){ return "lprint"; }
  static std::string description(){
    return "The lprint parameter specifies whether or not the results will\n"
           "be printed.  Setting it to 0 will not print, but 1 will print.";
  }
  static bool verify( const Value_t lprint ){
    return ( lprint == 0 or lprint == 1 );
  }
};
