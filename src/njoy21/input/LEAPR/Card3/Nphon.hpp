struct Nphon {
  using Value_t = int;
  static std::string name(){ return "nphon"; }
  static std::string description(){
    return
      "The nphon argument gives the order of the phonon expansion. For most\n"
      "applications, a fairly large number (e.g. 100) is appropriate.\n"
      "\n"
      "nphon has a default value of 100";
  }

  static Value_t defaultValue(){ return 100; }
  static bool verify( const Value_t& v ){ return v > 0; }
};
