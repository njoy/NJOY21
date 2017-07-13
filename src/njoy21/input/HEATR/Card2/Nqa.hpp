struct Nqa {
  using Value_t = int;
  static std::string name(){ return "nqa"; }
  static std::string description(){
    return
      "nqa is a optional integer argument specifying the number of desired\n"
      "q-values. As such, the nqa value is required to be non-negative, and\n"
      "no greater than 30. When unspecified, nqa defaults to zero.\n";
  }

  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return (i > -1) and (i <= 30 ); }
};
