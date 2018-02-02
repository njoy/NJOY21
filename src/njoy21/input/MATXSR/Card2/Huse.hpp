struct Huse {
  using Value_t = std::string;
  static std::string name(){ return "huse"; }
  static std::string description(){
    return "The huse parameter specifies the user id.  The default value is a\n"
           "blank string.  Up to 16 characters are allowed and they must be\n"
           "delimited by single quotes (') and ended by a forward slash (/).";
  }
  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t huse ){
    return huse.size() < 17;
  }
};
