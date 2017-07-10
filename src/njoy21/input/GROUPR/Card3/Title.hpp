struct Title {
  using Value_t = std::string;
  static std::string name(){ return "title"; }

  static std::string description(){
    return 
        "The title parameter is a descriptive character string up to 80 \n"
        "characters long.";
  }

  static bool verify( const Value_t& s ){ return s.length() < 81; }
};
