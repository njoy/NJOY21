struct Identa{
  using Value_t = int;
  static std::string name(){ return "identa"; }
  static std::string description(){
    return "The identa parameter specifies the ident of the time-dependent\n"
           "isotope.";
  }
  static bool verify( const Value_t identa ){
    return identa > -100;
  }
};
