struct Hmat{
  using Value_t = std::string;
  static std::string name(){ return "hmat"; }
  static std::string description(){
    return "The hmat parameter specifies the isotope identification.  The\n"
           "parameter accepts up to six characters delimited by single quotes\n"
           "(') and terminated by a forward slash (/).";
  }
  static bool verify( const Value_t hmat ){
    return hmat.size() < 7;
  }
};
