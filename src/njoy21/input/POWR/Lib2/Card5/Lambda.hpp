struct Lambda{
  using Value_t = double;
  static std::string name(){ return "lambda"; }
  static std::string description(){
    return "The lambda parameter specifies the lambda value for this isotope\n"
           "at this temperature.\n"
           "The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t lambda ){
    return lambda >= 0.0;
  }
};
