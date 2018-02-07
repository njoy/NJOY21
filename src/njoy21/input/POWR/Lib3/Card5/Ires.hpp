struct Ires{
  using Value_t = int;
  static std::string name(){ return "ires"; }
  static std::string description(){
    return "The ires parameter specifies the resonance absorber indicator.\n"
           " 0 = no\n"
           " 1 = yes";
  }
  static bool verify( const Value_t ires ){
    return ( ires == 0 or ires == 1 );
  }
};
