struct Holl {
  using Value_t = std::string;
  static std::string name(){ return "holl";}
  static std::string description(){
    return "Hollerith data (up to 72 characters).";
  }
  static bool verify( const Value_t s ){ return s.size() < 73; }
};
