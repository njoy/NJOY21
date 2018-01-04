struct Nholl{
  using Value_t = int;
  static std::string name(){ return "nholl"; }
  static std::string description(){
    return "The nholl parameter specifies the number of cards to be read for\n"
           "hollerith identification records.";
  }
  static bool verify( const Value_t nholl ){ return nholl >= 0; }
};
