struct Sgref{
  using Value_t = double;
  static std::string name(){ return "sgref"; }
  static std::string description(){
    return "The sgref parameter specifies the reference sigma value.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t sgref ){
    return sgref >= 0.0;
  }
};
