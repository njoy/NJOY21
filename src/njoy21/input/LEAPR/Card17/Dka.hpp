struct Dka {
  using Value_t = decltype( pow( 1.0 * angstrom, Ratio<-1> ) );
  static std::string name(){ return "dka"; }
  static std::string description() {
    return
      "dka specifies the increment used to space the kappa values provided in\n"
      "the card18 skappa input. The kappa values are used in the pair-\n"
      "correlation function that accounts for intermolecular interference at\n"
      "very low neutron energies. dka must only be used when nsk (Card 5\n"
      "input) is nonzero.\n"
      "\n"
      "The dka input should be in units of inverse angstroms, and must bei\n" 
      "greater than zero.";
  }
  
  static bool verify( const Value_t& dka ){ 
    return dka > 0.0 * pow( 1.0 * angstrom, Ratio<-1> );
  }
};
