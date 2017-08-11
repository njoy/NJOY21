struct Emax {
  using Value_t = Quantity< ElectronVolts >;
  static std::string name(){ return "emax"; }
  static std::string description(){
    return
      "The emax argument is the maximum energy for thermal treatment. For\n"
      "temperatures greater than 3000 Kelvin, emax and the energy grid are\n"
      "scaled by temp / 3000 (for free gas only). \n"
      "\n"
      "The emax input must be a decimal, and given in units of eV.";
  }
  
  static bool verify( const Value_t emax ){
    return ( emax > 0.0 * electronVolts ); 
  }
};
