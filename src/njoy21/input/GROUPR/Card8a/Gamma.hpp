struct Gamma {
  using Value_t = double;
  static std::string name(){ return "gamma"; }

  static std::string description(){
    return 
        "The gamma parameter specifies the fraction of admixed moderator\n"
        "cross section in external moderator cross section.\n"
        "\n"
        "The default value is 0, which means none.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t a ){ return a >= 0; }
};
