struct Ifopt{
  using Value_t = int;
  static std::string name(){ return "ifopt"; }
  static std::string description(){
    return "The ifopt parameter specifies the matrix blocking option. The\n"
           "options are:\n"
           "  1 - blocking by reaction\n"
           "  2 - blocking by legendre order";
  }
  static bool verify( const Value_t ifopt ){
    return ( ifopt == 1 or ifopt == 2 );
  }
};
