struct Htype{
  using Value_t = std::string;
  static std::string name(){ return "htype"; }
  static std::string description(){
    return "The htype parameter specifies the hollerith identifier for data\n"
           "types.";
  }
  static bool verify( const Value_t htype ){
    return htype.size() < 9;
  }
};
