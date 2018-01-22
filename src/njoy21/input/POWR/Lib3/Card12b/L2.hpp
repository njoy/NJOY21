struct L2{
  using Value_t = int;
  static std::string name(){ return "l2"; }
  static std::string description(){
    return "The l2 parameter specifies the highest energy group to which\n"
           "scattering occurs. The value must be greater than l1 and less\n"
           "than ngnd.";
  }
  static bool verify( const Value_t l2, const int l1, const int ngnd ){
    return ( l2 > l1 and l2 < ngnd );
  }
};
