struct Hsetid{
  using Value_t = std::string;
  static std::string name(){ return "hsetid"; }
  static std::string description(){
    return "The hsetid parameter specifies the hollerith identification\n"
           "of the set.  The parameter accepts up to 12 characters, is\n"
           "delimited by single quotes (') and terminated with a forward\n"
           "slash (/).  The default value is a blank string.";
  }
  static Value_t defaultValue(){ return ""; }
//  static bool verify( const Value_t hsetid ){
//    return hsetid.size() < 13;
//  }
};
