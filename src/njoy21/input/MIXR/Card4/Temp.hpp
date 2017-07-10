struct Temp {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "temp"; }
  static std::string description() {
    return
      "temp specifies the temperature in Kelvin that is used for all\n"
      "of the materials considered. The appropriate value for ENDF\n"
      "tapes is zero. The temperatures used for PENDF cases must be\n"
      "included on the PENDF tape.\n";
  }

  static bool verify( const Value_t& t ){ return t >= 0.0*kelvin; }
};
