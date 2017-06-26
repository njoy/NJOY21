struct Egg {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "egg"; }

  static std::string description() {
    return
        "The egg parameter is a list of (ngn+1) energy values (in eV). ngn is\n"
        "input on Card7a. These energy values are the bin boundaries for \n"
        "multigroup gamma cross sections.";
  }
  static bool verify( const Value_t& egg,
                      const int nboundaries ){
    auto found = std::find_if( egg.begin(), egg.end(),
                               [](auto& E){ return E <= 0.0*electronVolt; });

    if ( found != egg.end() ){
      Log::warning( "Negative energy value ({}) found at index {}",
                    *found, std::distance(egg.begin(), found));
      return false;
    } else {
      return ( long(egg.size()) == nboundaries );
    }
  }
};
