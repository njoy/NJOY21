struct Maxord{
  using Value_t = int;
  static std::string name(){ return "maxord"; }
  static std::string description(){
    return "The maxord parameter specifies the maximum legendre order.";
  }
  static bool verify( const Value_t maxord ){
    return maxord >= 0;
  }
};
