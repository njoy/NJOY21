struct Temp {
  using Value_t = std::vector< Quantity< Kelvin > >;
  static std::string name(){ return "temp"; }

  static std::string description() {
    return 
        "The temp argument is a list of temperatures (in Kelvin) to which the\n"
        "the unresolved resonances are produced.";
  }

  static bool verify( const Value_t& temps,
                      const Argument< GROUPR::Card2::Ntemp > & ntemp ){
    if ( long(temps.size()) != ntemp.value ){
      Log::info( "Incorrect number of temperatures read in." );
      return false;
    }
    // Make sure all temperatures are positive
    auto found = std::find_if( temps.begin(), temps.end(),
                               [](auto& E){ return E < 0.0*kelvin; });

    if ( found != temps.end() ){
      Log::info( "Negative temperature ({}) found at index {}",
                    *found, std::distance(temps.begin(), found));
      return false;
    } else {

      // Make sure temperatures are in increasing order
      for( size_t i=1; i < temps.size(); ++i ){
        if( temps[i-1] > temps[i] ){
          Log::warning( 
            "Temperatures are not in increasing order.\n"
             "Temperature at index {} ({}) > tempeature at index {} ({})",
                       temps[i-1], i-1, temps[i], i);
          return false;
        }
      }

      return true;
    }
  }
};
