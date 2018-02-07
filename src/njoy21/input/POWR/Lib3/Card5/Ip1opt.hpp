struct Ip1opt{
  using Value_t = int;
  static std::string name(){ return "ip1opt"; }
  static std::string description(){
    return "The ip1opt parameter specifies the behavior with respect to the\n"
           "p1 or p0 scattering matrices.\n"
           " 0 = calculate p1 matrices\n"
           " 1 = correct p0 scattering matrix ingroups.\n\n"
           " ***NOTE: if a p1 matrix is calculated for one of the isotopes\n"
           "          having a p1 matrix on the old library, file 6 on the\n"
           "          new library will be completely replaced.";
  }
  static bool verify( const Value_t ip1opt ){
    return ( ip1opt == 0 or ip1opt == 1 );
  }
};
