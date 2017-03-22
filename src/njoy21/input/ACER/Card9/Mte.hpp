struct Mte {
  using Value_t = int;
  static std::string name(){ return "mte"; }

  static std::string description() {
    return
        "The mte argument is the material number for the thermal elastic \n"
        "scattering.\n"
        "\n"
        "The deafault value is zero; a nonzero value is only needed for \n"
        "for materials that show elastic scattering.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& mte ){ return mte >= 0; }
};
