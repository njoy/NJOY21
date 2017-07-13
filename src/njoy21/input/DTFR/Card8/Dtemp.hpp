struct Dtemp {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "dtemp"; }
  static std::string description() {
    return
      "dtemp specifies the temperature in Kelvin that is used for the\n"
      "material considered. In DTFR, the user can specify that a given set\n"
      "of tables be prepared using one particular temperature (dtemp).";
  }
  
  static Value_t defaultValue(){ return 300*kelvin; }
  static bool verify( const Value_t& t ){ return t >= 0.0*kelvin; }
};
