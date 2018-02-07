struct Mtc {
  using Value_t = int;
  static std::string name(){ return "mtc"; }
  static std::string description(){
    return "The mtc parameter specifies the thermal elastic mt.\n"
           "The default value is zero (0), specifying none.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t mtc ){
    return mtc >= 0;
  }
};
