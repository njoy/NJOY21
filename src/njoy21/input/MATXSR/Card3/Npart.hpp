struct Npart{
  using Value_t = int;
  static std::string name(){ return "npart"; }
  static std::string description(){
    return "The npart parameter specifies the number of particles for which\n"
           "group structures are given.  The maximum number is 9.\n"
           "See NJOY2016 manual, Section 15.2, Table 12.";
  }
  static bool verify( const Value_t npart ){
    return ( npart > 0 and npart < 10 );
  }
};
