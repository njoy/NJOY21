struct Nzi {
  using Value_t = int;
  static std::string name(){ return "nzi"; }
  static std::string description(){
    return "The nzi parameter specifies the number of sigpo values desired.\n"
           "A negative value specifies that the first n sigpo values should\n"
           "be accepted.";
  }
  static bool verify( const Value_t nzi ){
    return ( nzi != 0 and std::abs( nzi ) < 21 );
  }
};
