struct Nqa {
  using Value_t = int;
  static std::string name(){ return "nqa"; }
  static std::string description(){
    return
      "nqa is a optional integer argument specifying the number of user-specified\n"
      "q-values desired. As such, the nqa value is required to be non-negative.\n"
      "When unspecified, this argument defaults to zero.\n";
  }

  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return (i > -1); }
};
