struct Ichix {
  using Value_t = int;
  static std::string name(){ return "ichix"; }
  static std::string description(){
    return "The ichix parameter specifies the fission chi representation. The\n"
           "available options are:\n\n"
           " -1 - vector (using groupr flux)\n"
           "  0 - none\n"
           "  1 - vector (using input flux)\n"
           " >1 - matrix";
  }
  static bool verify( const Value_t ichix ){
    return ichix > -2;
  }
};
