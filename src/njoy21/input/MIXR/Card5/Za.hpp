struct Za {
  using Value_t = int;
  static std::string name() { return "za"; }
  static std::string description(){
    return
      "The za argument is calculated to be 1000 * Z + A, where Z is the\n"
      "charge number and A is the atomic mass number for the mixture.";
  }
  static bool verify( const Value_t& z ){ return  z > 0  and  z <= 200000 ; }
};
