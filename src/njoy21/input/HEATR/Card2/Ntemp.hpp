struct Ntemp {
  using Value_t = int;
  static std::string name(){ return "ntemp"; }
  static std::string description(){
    return
      "ntemp is a optional integer argument specifying the number of temperatures\n"
      "from the input that input PENDF-format tape which should be processed.\n"
      "As such, the ntemp value is required to be non-negative. When unspecified,\n"
      "this argument defaults to zero, which denotes that ALL temperatures on\n"
      "the input PENDF-format tape should be processed";
  }

  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return (i > -1); }
};
