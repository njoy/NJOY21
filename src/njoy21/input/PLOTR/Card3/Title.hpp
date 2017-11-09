template< typename S >
struct Title {
  using Value_t = std::string;
  static std::string name(){ return S{}.c_str(); }

  static std::string description(){
    return 
        "The " + std::string( S{}.c_str() ) +
        "parameter is the title for a particular plot.  The default\n"
        "value is no title.  The character limit is 60.";
  }

  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t& s ){ return s.length() < 61; }
};
