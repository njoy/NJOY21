struct Tempd {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "tempd"; }

  static std::string description(){
    return 
        "The tempd argument specifies the absolute temperature for the \n"
        "material to be processed.";
  }

  static Value_t defaultValue(){ return 300*kelvin; }
  static bool verify( const Value_t& t ){ return t >= 0.0*kelvin; }
};
