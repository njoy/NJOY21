struct Nka {
  using Value_t = int;
  static std::string name(){ return "nka"; }
  static std::string description(){
    return
      "The nka input is the number of kappa values, and is used only for\n"
      "hydrogen or liquid deuterium cases. It is used to control the entry\n"
      "of the pair-correlation function used to account for intermolecular\n"
      "interference at very low neutron energies. nka is only used\n"
      "when nsk (Card5 input) is nonzero.\n"
      "\n"
      "nka must be a non-negative integer.";
 } 
  static bool verify( const Value_t nka ){ return nka >= 0; }
};
