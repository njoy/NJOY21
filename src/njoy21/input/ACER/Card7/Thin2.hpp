struct Thin2 {
  using Value_t = double;
  static std::string name() { return "thin2"; }

  static std::string description(){
    return 
        "The thin2 argument specifies the energy above which to use all\n"
        "energies (eV)---i.e., no thinning above this energy.\n";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t& e2 ){ return e2 >= 0.0; }
};
