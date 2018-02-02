struct Huse {
  using Value_t = std::string;
  static std::string name(){ return "huse";}
  static std::string description(){
    return "Hollerith user identification (up to 16 characters).";
  }
  static bool verify( const Value_t s ){ return s.size() < 17; }
};
