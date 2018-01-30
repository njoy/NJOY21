struct Ip1opt {
  using Value_t = int;
  static std::string name(){ return "ip1opt"; }
  static std::string description(){
    return "The ip1opt parameter specifies whether or not to include the p1\n"
           "matricies.\n"
           "  0 = yes\n"
           "  1 = no, correct p0 ingroups (default)";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t ip1opt ){
    return ip1opt == 1 or ip1opt == 0;
  }
};
