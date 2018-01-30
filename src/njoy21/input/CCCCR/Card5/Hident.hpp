struct Hident{
  using Value_t = std::string;
  static std::string name(){ return "hident"; }
  static std::string description(){
    return "The hident parameter specifies the identifier of the endf data\n"
           "source library.  The parameter accepts up to six characters\n"
           "delimited by single quotes (') and terminated by a forward\n"
           "slash (/).";
  }
  static bool verify( const Value_t hident ){
    return hident.size() < 7;
  }
};
