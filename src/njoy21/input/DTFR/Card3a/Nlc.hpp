struct Nlc {
  using Value_t = int;
  static std::string name() { return "nlc"; }
  static std::string description() {
    return
      "Nlc is the number of coherent legendre orders, and can be used to\n"
      "truncate the anisotropy of the coherent term, if desired. Nlc must\n"
      "be valued greater than or equal to 0.";
  }
  
  static Value_t defaultValue(){ return 0; }
  static bool verify( Value_t i ) { return i >= 0; }

};
