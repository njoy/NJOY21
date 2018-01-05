struct Word{
  using Value_t = std::string;
  static std::string name(){ return "word"; }
  static std::string description(){
    return "The word parameter specifies a description of the nuclide.\n"
           "The description can be up to 16 characters, is delimited by\n"
           "asterisks (*), ends with a forward slash (/), and defaults to\n"
           "being blank.";
  }
  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t word ){
    return word.size() < 17;
  }
};
