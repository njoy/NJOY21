struct Jsigz {
  using Value_t = int;
  static std::string name(){ return "jsigz"; }

  static std::string description(){
    return 
        "The jsigz argument specifies the index of reference sigma zero in\n"
        "the sigz array.\n"
        "\n"
        "The default value is 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t j ){ return j >= 0; }
};

