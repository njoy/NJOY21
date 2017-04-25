struct Egn {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "egn"; }

  static std::string description() {
    return
        "The egn parameter is a list of (ngn+1) energy values (in eV). ngn is\n"
        "input on Card6a. These energy values are the bin boundaries for \n"
        "multigroup cross sections.";
  }
  static bool verify( const Value_t& egn,
                      const int nboundaries ){
//                    const Argument< GROUPR::Card6a::Ngn > & ngn ){
    Log::debug("size: {}, value: {}", egn.size(), nboundaries);
//  if( long(egn.size()) != nboundaries.value + 1 ){
//    Log::info( "Incorrect number of energy boundaries read in." );
//    return false;
//  }
    auto found = std::find_if( egn.begin(), egn.end(),
                               [](auto& E){ return E <= 0.0*electronVolt; });

    if ( found != egn.end() ){
      Log::warning( "Negative energy value ({}) found at index {}",
                    *found, std::distance(egn.begin(), found));
      return false;
    } else {
      return ( long(egn.size()) == nboundaries );
    }
  }
};
