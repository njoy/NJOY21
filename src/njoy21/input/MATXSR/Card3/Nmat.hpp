struct Nmat{
  using Value_t = int;
  static std::string name(){ return "nmat"; }
  static std::string description(){
    return "The nmat parameter specifies the number of materials desired.";
  }
  static bool verify( const Value_t nmat ){ return nmat >= 0; }
};
