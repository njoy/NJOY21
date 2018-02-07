struct Itrc{
  using Value_t = int;
  static std::string name(){ return "itrc"; }
  static std::string description(){
    return "The itrc parameter specifies the transport correction option.\n"
           " 0 = no (default)\n"
           " 1 = yes\n";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t itrc ){
    return ( itrc == 0 or itrc == 1 );
  }
};
