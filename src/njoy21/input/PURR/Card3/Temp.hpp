struct Temp {
  using Value_t = std::vector< Quantity< Kelvin > >;
  static std::string name(){ return "temp"; }

  static std::string description() {
    return 
        "The temp argument is a list of temperatures (in Kelvin) to which the\n"
        "the unresolved resonances are produced.";
  }

  static bool verify( const Value_t& temps,
                      const Argument< Card2::Ntemp > & ntemp ){
    auto found = std::find_if( temps.begin(), temps.end(),
                               [](auto& E){ return E < 0.0*kelvin; });

    if ( found != temps.end() ){
      Log::warning( "Negative temperature ({}) found at index{}",
                    *found, std::distance(temps.begin(), found));
      return false;
    } else {
      return ( long(temps.size()) == ntemp.value );
    }
  }
  
};
