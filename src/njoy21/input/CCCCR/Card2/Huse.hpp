struct Huse{
  using Value_t = std::string;
  static std::string name(){ return "huse"; }
  static std::string description(){
    return "The huse parameter specifies the user identification.\n\n"
           "The parameter accepts up to 12 characters, delimited by\n"
           "single quotes (') and ends with a forward slash (/).  The default\n"
           "value is blank.";
  }
  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t huse ){
    return huse.size() < 13;
  }
};
