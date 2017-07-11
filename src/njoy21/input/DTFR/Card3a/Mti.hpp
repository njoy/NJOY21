struct Mti {
  using Value_t = int;
  static std::string name() { return "mti"; }
  static std::string description() {
    return
      "Mti is the MT number for thermal incoherent cross sections to be\n"
      "extracted from the GENDF tape. As with all MT numbers, Mti must be\n"
      "three digits or less.";
  }
  
  static bool verify( Value_t i ) { return i <= 999 && i >= 0; }

};
