struct Hmat {
  using Value_t = std::string;
  static std::string name(){ return "hmat"; }
  static std::string description(){
    return "Hollerith name for a material (up to 8 characters).";
  }
  static bool verify( const Value_t s ){ return s.size() < 9; }
};
