struct Tempr {
  using Value_t = std::vector< Quantity< Kelvin > >;
  static std::string name(){ return "tempr"; }

  static std::string description() {
    return 
      "The tempr argument is a list of ntemp temperatures (where ntemp was\n"
      "defined in card2). These tempr inputs are the temperatures at which\n"
      "the thermal scattering cross sections are evaluated. Each\n"
      "temperature is in kelvin, and therefore must be positive. Additionally\n"
      "the temperature entries must be sorted in increasing order.";
  }

  static bool verify( const Value_t& temps,
                      const Argument< THERMR::Card2::Ntemp > & ){

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
        dis-1, *(unsortedStart-1), dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
