struct Qbar {
  using Value_t = ENDFtk::TAB1;
  static std::string name(){ return "qbar"; }
  static std::string description(){
    return
    "The qbar input is a endf format tab1 record giving the energy released\n"
    "per reaction as a function of particle energy. qbar entries are used\n"
    "for Card5 qa values if a qa value has an absolute value greater than\n"
    "99 MeV.\n"
    "\n"
    "All x-values in the tab1 input must be greater than zero, and provided\n"
    "in increasing order.";
  }

  static bool verify( const Value_t& qbar ){
    const auto energies = qbar.x();
    return energies.size() and energies[0] > 0;
  }    
};
