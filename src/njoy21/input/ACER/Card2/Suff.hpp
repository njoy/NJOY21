struct Suff {
  using Value_t = double;
  static std::string name(){ return "suff"; }

  static std::string description(){
    return
        "The suff parameter specifies the suffix of the ZAID. It is appended \n"
        "to the ZA for the material. \n"
        "\n"
        "It is a two-digit floating point value (e.g., .70, .71, .80). The \n"
        "default value is .00. Specifying a negative value leaves the old \n"
        "ZAID unchanged (from previous ACER run).";
  }

  static Value_t defaultValue(){ return 0.0; }
  static bool verify( Value_t ){ return true; }
};
