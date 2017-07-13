struct Mtc {
  using Value_t = int;
  static std::string name() { return "mtc"; }
  static std::string description() {
    return
      "mtc is the MT number for thermal coherent cross sections to be\n"
      "extracted from the GENDF tape. As with all MT numbers, mtc must be\n"
      "three digits or less.";
  }
  
  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ) { return i <= 999 && i >= 0; }

};
