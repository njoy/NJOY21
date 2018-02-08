struct Nek {
  using Value_t = int;
  static std::string name(){ return "nek"; }
  static std::string description(){
    return "The nek parameter specifies the number of derived cross section\n"
           "energy ranges.  If zero, all cross sections are independent.\n"
           "The maximum allowed value is 50.";
  }
  static bool verify( const Value_t nek ){
    return ( nek >= 0 and nek < 51 );
  }
};
