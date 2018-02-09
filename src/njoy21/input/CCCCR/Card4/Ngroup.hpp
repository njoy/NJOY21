struct Ngroup{
  using Value_t = int;
  static std::string name(){ return "ngroup"; }
  static std::string description(){
    return "The ngroup parameter specifies the number of neutron energy\n"
           "groups.";
  }
  static bool verify( const Value_t ngroup ){
    return ngroup > 0;
  }
};
