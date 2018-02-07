struct Izref{
  using Value_t = int;
  static std::string name(){ return "izref"; }
  static std::string description(){
    return "The izref parameter specifies the reference sigma zero for the\n"
           "elastic matrix.  The default value is one (1).";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t izref ){
    return izref >= 0;
  }
};
