struct Smin {
  using Value_t = double;
  static std::string name(){ return "smin"; }
  static std::string description(){
    return "The smin parameter specifies the minimum S(alpha,beta) stored in\n"
           "file.  The default is 1e-75.";
  }
  static Value_t defaultValue(){ return 1.e-75; }
  static bool verify( const Value_t smin ){
    return smin > 0;
  }
};
