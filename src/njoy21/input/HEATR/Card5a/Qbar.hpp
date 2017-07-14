struct Qbar {
  using Value_t = ENDFtk::TAB1;
  static std::string name(){ return "qbar"; }
  static std::string description(){
    return
    "The qbar input is a endf format tab1 record giving qbar vs. energy.\n"
    "qbar entries are substituted in for qa values if the qa value has an\n"
    "absolute value greater than 99 MeV.";
  }

  static bool verify( const Value_t& qbar ){
    return ( qbar.x().at( 0 ) > 0 );
  }    
};
