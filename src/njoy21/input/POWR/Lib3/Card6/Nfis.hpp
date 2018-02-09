struct Nfis{
  using Value_t = int;
  static std::string name(){ return "nfis"; }
  static std::string description(){
    return "The nfis parameter specifies the number of fissionable burnup\n"
           "isotopes.";
  }
  static bool verify( const Value_t nfis ){
    return nfis >= 0;
  }
};
