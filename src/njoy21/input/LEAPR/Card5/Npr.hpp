struct Npr {
  using Value_t = int;
  static std::string name(){ return "npr"; }
  static std::string description(){
    return
      "The npr argument is the number of principle scattering atoms in a\n"
      "compound. npr must be a positive interger.";
  }
  static bool verify( const Value_t& npr ){ return npr > 0; }
};
