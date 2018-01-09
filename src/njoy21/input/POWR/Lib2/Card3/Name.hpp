struct Name{
  using Value_t = std::string;
  static std::string name(){ return "name"; }
  static std::string description(){
    return "The name parameter specifies the hollerith name of the isotope.\n"
           "The name is up to 10 characters, delimited with asterisks (*),\n"
           "and terminated with a forward slash (/).  The default value is\n"
           "blank.";
  }
  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t name ){
    return name.size() < 11;
  }
};
