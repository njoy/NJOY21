struct Temp {
  using Value_t = std::vector< Quantity< Kelvin > >;
  static std::string name(){ return "temp"; }

  static std::string description() {
    return 
        "The temp argument is a list of temperatures (in Kelvin) to which the\n"
        "the unresolved resonances are produced.";
  }

  static bool verify( const Value_t& temps,
                      const Argument< GROUPR::Card2::Ntemp > & ){
    // Make sure all temperatures are positive
    auto found = std::find_if( temps.begin(), temps.end(),
                               [](auto& E){ return E < 0.0*kelvin; });
    if ( found != temps.end() ){
      Log::info( "Negative temperature ({}) found at index {}",
                    *found, std::distance(temps.begin(), found));
      return false;
    } 

    // Make sure temperatures are in increasing order
    auto unsortedStart = std::is_sorted_until( temps.begin(), temps.end() );
    if( unsortedStart != temps.end() ){
      auto dis = std::distance( temps.begin(), unsortedStart );
      Log::warning( "Temperatures are not in increasing order.");
      Log::info( "Temperature at index {} ({}) > temperature at index {} ({})",
                   dis-1, unsortedStart[-1], dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
