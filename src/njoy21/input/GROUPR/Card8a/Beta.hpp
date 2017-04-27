struct Beta {
  using Value_t = double;
  static std::string name(){ return "beta"; }

  static std::string description(){
    return 
        "The beta parameter specifies the admixed moderator cross section (in\n"
        "banrs per absorber atom)."
        "\n"
        "The default value is 0, which means none.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t a ){ return a >= 0; }
};
