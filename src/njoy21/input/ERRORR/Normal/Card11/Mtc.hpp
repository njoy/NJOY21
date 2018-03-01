struct Mtc {
  using Value_t = int;
  static std::string name(){ return "mtc"; }
  static std::string description(){
    return "The mtc parameter specifies the MT of the material/MT which\n"
           "replaces the material/MT combination specified previously on this\n"
           "card.";
  }
  static bool verify( const Value_t mtc ){
    return ( mtc > 0 and mtc < 1000 );
  }
};
