struct Fehi {
  using Value_t = Quantity< ElectronVolt >;

  static std::string name(){ return "fehi"; }
  static std::string description(){
    return 
        "The fehi parameter specifies the energy point between the computed\n"
        "flux and the bondarenko calculated flux. This energy range must be within the \n"
        "resolve resonance range.";
  }

  static bool verify( Value_t f ){ return f > 0.0*electronVolt; }
};
