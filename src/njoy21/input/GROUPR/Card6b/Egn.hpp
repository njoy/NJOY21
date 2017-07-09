struct Egn {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "egn"; }

  static std::string description() {
    return
        "The egn parameter is a list of (ngn+1) energy values (in eV). ngn is\n"
        "input on Card6a. These energy values are the bin boundaries for \n"
        "multigroup neutron cross sections.";
  }
  static bool verify( const Value_t& egn,
                      const int nboundaries ){
    if( long(egn.size()) != nboundaries ){
      Log::info( "Incorrect number of energy boundaries" );
      return false;
    }
    auto found = std::find_if( egn.begin(), egn.end(),
                               [](auto& E){ return E <= 0.0*electronVolt; });
    if ( found != egn.end() ){
      Log::warning( "Negative energy value ({}) found at index {}",
                    *found, std::distance(egn.begin(), found));
      return false;
    }

    // Make sure enerby boundaries are in increasing order
    auto unsortedStart = std::is_sorted_until( egn.begin(), egn.end() );
    if( unsortedStart != egn.end() ){
      auto dis = std::distance( egn.begin(), unsortedStart );
      Log::warning( "Energy boundaries are not in increasing order.");
      Log::info( "Energy boundary at index {} ({}) > boundary at index {} ({})",
                   dis-1, *(unsortedStart-1), dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
