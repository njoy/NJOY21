struct Hisnm{
  using Value_t = std::string;
  static std::string name(){ return "hisnm"; }
  static std::string description(){
    return "The hisnm parameter specifies the hollerith isotope label.  The\n"
           "parameter accepts up to six characters delimited by single quotes\n"
           "(') and terminated by a forward slash (/).";
  }
  static bool verify( const Value_t hisnm ){
    return hisnm.size() < 7;
  }
};
