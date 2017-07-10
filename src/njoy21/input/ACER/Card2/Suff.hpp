struct Suff {
  using Value_t = std::string;
  static std::string name(){ return "suff"; }

  static std::string description(){
    return
        "The suff parameter specifies the suffix of the ZAID. It is appended \n"
        "to the ZA for the material. \n"
        "\n"
        "It is a two-digit string (e.g., .70, .71, .80). The \n"
        "default value is .00. \n"
        "\n"
        "Specifying a negative value when iopt=7--9 leaves the old \n"
        "ZAID unchanged (from previous ACER run).";
  }

  static Value_t defaultValue(){ return ".00"; }
  static bool verify( Value_t s ){ 
    static std::regex verifyPattern( "[-]?\\.[0-9]{2}",  
                                     std::regex_constants::ECMAScript);
    return std::regex_match( s, verifyPattern );
  }
};
