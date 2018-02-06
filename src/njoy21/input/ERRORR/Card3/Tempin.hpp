struct Tempin {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "tempin"; }
  static std::string description(){
    return "The tempin parameter specifies the temperature in Kelvin.  The\n"
           "default value is 300K.";
  }
  static Value_t defaultValue(){ return 300*kelvin; }
  static bool verify( const Value_t tempin ){
    return ( tempin >= 0.0*kelvin );
  }
};
