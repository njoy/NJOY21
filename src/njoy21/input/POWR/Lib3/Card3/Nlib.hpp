struct Nlib {
  using Value_t = int;
  static std::string name(){ return "nlib"; }
  static std::string description(){
    return "The nlib parameter specifies the number of the library.";
  }
  static bool verify( const Value_t nlib ){
    return nlib >= 0;
  }
};
