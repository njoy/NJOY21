struct Ntype{
  using Value_t = int;
  static std::string name(){ return "ntype"; }
  static std::string description(){
    return "The ntype parameter specifies the number of data types in the set.";
  }
  static bool verify( const Value_t ntype ){ return ntype >= 0; }
};
