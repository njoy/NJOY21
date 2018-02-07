struct Mtc{
  using Value_t = int;
  static std::string name(){ return "mtc"; }
  static std::string description(){
    return "The mtc parameter specifies the thermal elastic mt.";
  }
  static bool verify( const Value_t mtc ){
    return ( mtc > 0 and mtc < 10000 );
  }
};
