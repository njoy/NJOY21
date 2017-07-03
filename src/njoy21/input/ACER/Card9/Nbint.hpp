struct Nbint {
  using Value_t = int;
  static std::string name(){ return "nbint"; }

  static std::string description() {
    return
        "The nbint argument specifies the number of bins for incoherent\n"
        "scattering.\n"
        "\n"
        "The default value is 16.";
  }

  static Value_t defaultValue(){ return 16; }
  static bool verify( const Value_t& nbint ){ return nbint > 0; }
};
