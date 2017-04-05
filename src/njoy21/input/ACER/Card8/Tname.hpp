struct Tname {
//using Value_t = optional< std::string >;
  using Value_t = std::string;
  static std::string name(){ return "tname"; }

  static std::string description(){
    return
        "The tname parameter specifies the thermal ZAID name.\n"
        "\n"
        "The parameter must be less than seven characters long.";
  }

//jtatic Value_t defaultValue(){ return std::nullopt_t(); }
//static bool verify( const Value_t& s ){ return s->length() < 7; }
  static Value_t defaultValue(){ return "      "; }
  static bool verify( const Value_t& s ){ return s.length() < 7; }
};
