struct C {
  using Value_t = double;
  static std::string name(){ return "c"; }
  static std::string description(){
    return
      "The c argument is the diffusion constant for the desired rho(E) freq.\n"
      "distribution. Note that the twt input immediate preceding c on Card13\n"
      "indicates whether a translational term is desired. c decides whether\n"
      "this translational term is a free-gas law (c = 0.0) or a diffusive\n"
      "law (c > 0.0).";
  }
  static bool verify( const Value_t& c ){ return c >= 0.0; }
};
