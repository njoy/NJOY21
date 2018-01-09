struct Mubar{
  using Value_t = double;
  static std::string name(){ return "mubar"; }
  static std::string description(){
    return "The mubar parameter specifies the mubar value for this isotope\n"
           "at this temperature.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t mubar ){
    return mubar >= 0.0;
  }
};
