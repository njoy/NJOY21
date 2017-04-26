struct Alpha2 {
  using Value_t = double;
  static std::string name(){ return "alpha2"; }

  static std::string description(){
    return 
        "The alpha2 parameter specifies the alpha value for the admixed\n"
        "moderator when calculating the moderator integral.\n"
        "\n"
        "The default value is 0, which means none.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t a ){ return a >= 0; }
};
