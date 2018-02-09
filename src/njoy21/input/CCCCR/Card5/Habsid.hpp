struct Habsid{
  using Value_t = std::string;
  static std::string name(){ return "habsid"; }
  static std::string description(){
    return "The habsid parameter specifies the hollerith absolute isotope\n"
           "label.  The parameter accepts up to six characters delimited by\n"
           "single quotes (') and terminated by a forward slash (/).";
  }
  static bool verify( const Value_t habsid ){
    return habsid.size() < 7;
  }
};
