struct Ecapt {
  using Value_t = double;
  static std::string name(){ return "ecapt"; }
  static std::string description(){
    return "The ecapt parameter specifies the total thermal energy per\n"
           "capture in W*sec/capture.";
  }
  static bool verify( const Value_t ecapt ){
    return ecapt >= 0.0;
  }
};
