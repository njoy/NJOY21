struct Nti {
  using Value_t = int;
  static std::string name(){ return "nti"; }
  static std::string description(){
    return "The nti parameter specifies the number of temperatures desired.\n"
           "A negative value specifies that the first n temperatures should\n"
           "be accepted.";
  }
  static bool verify( const Value_t nti ){
    return ( nti != 0 and std::abs( nti ) < 21 );
  }
};
