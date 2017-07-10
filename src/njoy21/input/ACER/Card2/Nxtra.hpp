struct Nxtra {
  using Value_t = int;
  static std::string name(){ return "nxtra"; }

  static std::string description(){
    return
        "The nxtra parameter is the number of extra (iz, aw) pairs of values\n"
        "to be read on card 4.\n"
        "\n"
        "The default value is 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t n ){ 
    return ( n >= 0 ) and ( n <= 16 ); }
};
