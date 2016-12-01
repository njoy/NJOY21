struct Tempr {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "tempr"; }

  static std::string description(){
    return 
        "The tempr argument specifies the temperature (in Kelvin) to which\n"
        "resonances are reconstructed.\n"
        "\n"
        "Specifying a non-zero temperature activates a special feature of \n"
        "RECONR if Single-Level Breit Wigner (SLBW) or Adler-Adler parameters\n"
        "are used to describe the resonance parameters. This feature will \n"
        "reconstruct the resonances to the specified temperature using an \n"
        "approximate Doppler-broadening algorithm.";
  }

  static Value_t defaultValue(){ return 0.0*kelvin; }
  static bool verify( const Value_t& t ){ return t >= 0.0*kelvin; }
};
