struct Xi{
  using Value_t = double;
  static std::string name(){ return "xi"; }
  static std::string description(){
    return "The xi parameter specifies xi for this isotope at this\n"
           "temperature.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t xi ){
    return xi >= 0.0;
  }
};
