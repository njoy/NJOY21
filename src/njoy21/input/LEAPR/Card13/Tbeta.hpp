struct Tbeta {
  using Value_t = double;
  static std::string name(){ return "tbeta"; }
  static std::string description(){
    return
      "The tbeta input is the normalization for the desired continuous\n"
      "frequency distribution, rho(E). tbeta must be greater than zero."; 
  }
  static bool verify( const Value_t& tbeta ){ return tbeta > 0.0; }
};
