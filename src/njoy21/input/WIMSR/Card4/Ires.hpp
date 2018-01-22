struct Ires {
  using Value_t = int;
  static std::string name(){ return "ires"; }
  static std::string description(){
    return "The ires parameter specifies whether or not resonance absorber\n"
           "temperatures are processed and, if so, how many.";
  }
  static bool verify( const Value_t ires ){
    return ires >= 0;
  }
};
