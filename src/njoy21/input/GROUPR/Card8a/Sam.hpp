struct Sam {
  using Value_t = Quantity< Barn >;
  static std::string name(){ return "sam"; }

  static std::string description(){
    return 
        "The sam parameter specifies the admixed moderator cross section (in\n"
        "banrs per absorber atom)."
        "\n"
        "The default value is 0, which means none.";
  }

  static Value_t defaultValue(){ return 0*barn; }
  static bool verify( const Value_t a ){ return a >= 0*barn; }
};
