struct L1{
  using Value_t = int;
  static std::string name(){ return "l1"; }
  static std::string description(){
    return "The l1 parameter specifies the lowest energy group to which\n"
           "scattering occurs. The value must be greater than or zero and\n"
           "less than ngnd.";
  }
  static bool verify( const Value_t l1, const int ngnd ){
    return ( l1 >= 0 and l1 < ngnd );
  }
};
