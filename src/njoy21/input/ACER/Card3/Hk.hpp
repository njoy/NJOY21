struct Hk {
  using Value_t = std::string;
  static std::string name(){ return "hk"; }

  static std::string description(){
    return 
        "The hk parameter is a descriptive character string up to 70 \n"
        "characters long.";
  }

  static bool verify( const Value_t& s ){ return s.length() < 71; }
};
