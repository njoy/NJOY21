struct Title {
  using Value_t = std::string;
  static std::string name(){ return "title"; }

  static std::string description(){
    return 
      "The title parameter is a descriptive character string up to 80 \n"
      "characters long. The title string is for the user's convenience,\n"
      "and does not go into the output ENDF.";
  }

  static bool verify( const Value_t& s ){ return s.length() < 81; }
};
