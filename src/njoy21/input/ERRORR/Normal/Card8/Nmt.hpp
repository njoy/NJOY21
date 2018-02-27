struct Nmt {
  using Value_t = int;
  static std::string name(){ return "nmt"; }
  static std::string description(){
    return "The nmt parameter specifies the number of materials to be\n"
           "processed for covariance data. The value can be as high as 150.";
  }
  static bool verify( const Value_t nmt ){
    return ( nmt > 0 and nmt < 151 );
  }
};
