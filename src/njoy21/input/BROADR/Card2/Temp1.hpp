struct Temp1 {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "temp1"; }
  static std::string description(){
    return
      "temp1 is an optional argument specifying a temperature in Kelvin.\n"
      "The argument value specifies the reference temperature from which\n"
      "broadening operations should begin. This useful when the input PENDF\n"
      "tape is a result of a previous BROADR command (which may contain\n"
      "multiple temperature values). When unspecified, temp1 defaults to\n"
      "zero kelvin";
  }

  static Value_t defaultValue(){ return 0.0 * kelvin; }
  static bool verify( Value_t v ){ return v >= (0.0 * kelvin); }
};
