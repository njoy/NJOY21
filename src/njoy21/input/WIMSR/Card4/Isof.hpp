struct Isof {
  using Value_t = int;
  static std::string name(){ return "isof"; }
  static std::string description(){
    return "The isof parameter specifies whether or not the fission spectrum\n"
           "will be included.\n"
           "  0 = do not include fission spectrum (default)\n"
           "  1 = include fission spectrum";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t isof ){
    return isof == 1 or isof == 0;
  }
};
