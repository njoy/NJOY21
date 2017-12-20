struct Jp1 {
  using Value_t = int;
  static std::string name(){ return "jp1"; }
  static std::string descritpion(){
    return "The jp1 parameter specifies which type of transport correction to\n"
           "the neutron current should be used.\n"
           "  0 = use p1-flux for transport correction (default)\n"
           " >0 = read in jp1 values of the neutron current spectrum from\n"
           "      input";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t jp1 ){
    return jp1 >= 0;
  }
};
