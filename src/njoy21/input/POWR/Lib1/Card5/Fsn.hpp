struct Fsn{
  using Value_t = std::string;
  static std::string name(){ return "fsn"; }
  static std::string description(){
    return "The fsn parameter specifies the title of the fission spectrum.\n"
           "The title can be up to 40 characters, delimited with asterisks\n"
           "(*), and ended with a forward slash (/).  The default is blank.";
  }
  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t fsn ){
    return fsn.size() < 41;
  }
};
