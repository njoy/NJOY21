struct Sigpot {
  using Value_t = Quantity< Barn >;
  
  static std::string name(){ return "sigpot"; }
  static std::string description(){
    return
        "The sigpot parameter gives an estimate of the potential scattering\n"
        "cross section. The actual value for sigpot is not very critical---a \n"
        "number near 10 barns is typical for fissionable materials.";
  }

  static bool verify( Value_t s ){ return s > 0*barn; }
};
