struct Title {
  using Value_t = std::string;
  static std::string name(){ return "title"; }

  static std::string description(){
    return 
        "The title parameter is title for a particular plot.  The default\n"
        "value is no title.  The character limit is 60.";
  }

  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t& s ){ return s.length() < 61; }
};
