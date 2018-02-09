struct Posr{
  using Value_t = int;
  static std::string name(){ return "posr"; }
  static std::string description(){
    return "The posr parameter specifies the position of this isotope in\n"
           "resonance tabulation in cpmlib.";
  }
  static bool verify( const Value_t posr ){
    return posr >= 0;
  }
};
