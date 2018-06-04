struct Za {
  using Value_t = long;
  static std::string name() { return "za"; }
  static std::string description(){
    return
      "The za argument is normally calculated to be 1000 * Z + A, where Z and A\n"
      "are atomic number and the atomic mass number, respecively, for the\n"
      "principle scatterer. It is still possible to enter a za between 100 and\n"
      "1000 but this is discouraged.";
  }
  static bool verify( const Value_t& z ){ return z > 100 and z < 200000 ; }
};
