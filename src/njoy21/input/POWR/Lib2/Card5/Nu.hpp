struct Nu{
  using Value_t = double;
  static std::string name(){ return "nu"; }
  static std::string description(){
    return "The nu parameter specifies the nu value for this isotope at\n"
           "this temperature.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t nu ){
    return nu >= 0.0;
  }
};
