struct Egg {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "egg"; }

  static std::string description() {
    return
        "The egg parameter is a list of (ngg+1) energy values (in eV). ngg is\n"
        "input on Card4 Ngg. These energy values are the bin boundaries for \n"
        "multigroup gamma cross sections.";
  }
  static bool verify( const Value_t& egg,
                      const int nboundaries ){
    if( long(egg.size()) != nboundaries ){
      Log::info( "Incorrect number of energy boundaries" );
      return false;
    }
    auto found = std::find_if( egg.begin(), egg.end(),
                               [](auto& E){ return E <= 0.0*electronVolt; });
    if ( found != egg.end() ){
      Log::warning( "Negative energy value ({}) found at index {}",
                    *found, std::distance(egg.begin(), found));
      return false;
    }

    // Make sure enerby boundaries are in increasing order
    auto unsortedStart = std::is_sorted_until( egg.begin(), egg.end() );
    if( unsortedStart != egg.end() ){
      auto dis = std::distance( egg.begin(), unsortedStart );
      Log::warning( "Energy boundaries are not in increasing order.");
      Log::info( "Energy boundary at index {} ({}) > boundary at index {} ({})",
                   dis-1, *(unsortedStart-1), dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
