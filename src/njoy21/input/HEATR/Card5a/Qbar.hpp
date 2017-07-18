struct Qbar {
  using Value_t = ENDFtk::TAB1;
  static std::string name(){ return "qbar"; }
  static std::string description(){
    return
    "The qbar input is a endf format tab1 record giving qbar vs. energy.\n"
    "qbar entries are used for Card5 qa values if a qa value has an\n"
    "absolute value greater than 99 MeV.\n"
    "\n"
    "All x-values in the tab1 input must be greater than zero, and provided\n"
    "in increasing order.";
  }

  static bool verify( const Value_t& qbar ){
    return ( qbar.x().at( 0 ) > 0 );
  }    
};
