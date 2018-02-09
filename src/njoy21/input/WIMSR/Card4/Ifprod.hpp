struct Ifprod {
  using Value_t = int;
  static std::string name(){ return "ifprod"; }
  static std::string description(){
    return "The ifprod parameter specifies whether or not fission products\n"
           "should be included and, if so, whether or not to use the\n"
           "associated resonance tables.\n"
           "  0 = not a fission product (default)\n"
           "  1 = fission product, no resonance tables\n"
           "  2 = fission product, resonance tables";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t ifprod ){
    return ifprod == 0 or ifprod == 1 or ifprod == 2;
  }
};
