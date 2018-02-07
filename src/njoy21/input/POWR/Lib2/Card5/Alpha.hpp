struct Alpha{
  using Value_t = double;
  static std::string name(){ return "alpha"; }
  static std::string description(){
    return "The alpha parameter specifies the alpha value for this isotope\n"
           "at this temperature.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t alpha ){
    return alpha >= 0.0;
  }
};
