struct Inorf {
  using Value_t = int;
  static std::string name(){ return "inorf"; }
  static std::string description(){
    return "The inorf parameter specifies whether or not resonance fission\n"
           "should be included.\n"
           "  0 = include resonance fission (default)\n"
           "  1 = include fission spectrum";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t inorf ){
    return inorf == 0 or inorf == 1;
  }
};
