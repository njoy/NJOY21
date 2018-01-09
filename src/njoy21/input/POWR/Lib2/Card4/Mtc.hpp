struct Mtc{
  using Value_t = double;
  static std::string name(){ return "mtc"; }
  static std::string description(){
    return "The mtc parameter specifies the thermal eleastic mt.\n"
           "The default value is 0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t mtc ){
    return mtc >= 0.0;
  }
};
