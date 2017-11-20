struct Hpart{
  using Value_t = std::string;
  static std::string name(){ return "hpart"; }
  static std::string description(){
    return "The hpart parameter specifies the hollerith identifier for\n"
           "particles.";
  }
  static bool verify( const Value_t hpart ){
    return hpart.size() < 9;
  }
};
