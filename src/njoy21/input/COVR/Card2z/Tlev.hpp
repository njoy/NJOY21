struct Tlev {
  using Value_t = std::vector< double >;
  
  static std::string name(){ return "tlev"; }
  static std::string description(){ 
    return
      "tlev specifies the correlation matrix interval limits to be used\n"
      "with Card2's icolor option. It is assumed that the lower boundary\n"
      "of the first boundary is 0, but the user must specify the upper\n"
      "limits that define regions between 0 and 1, with one being the upper\n"
      "limit to the last boundary.\n"
      "\n"
      "tlev has nlev entries (where nlev is a card2z entry). tlev entries\n"
      "are all decimal values greater than zero and no greater than one.\n"
      "All tlev enties are provided in increasing order.\n"
      "\n"
      "If no tlev input is provided, then the default entry of\n"
      "                 0.001, 0.1, 0.2, 0.3, 0.6, 1.0  \n"
      "is used. However, if the default value is used, then no nlev input may\n"
      "be provided, thus invoking nlev default value of 6.";
  } 
  
  static bool verify( const Value_t& tlevs,
                      const Argument< COVR::Card2z::Nlev > & ){

    // Make sure all tlev values are positive
    auto found = std::find_if( tlevs.begin(), tlevs.end(),
      [](auto& t){ return t <= 0.0 or t > 1.0; });
    if ( found != tlevs.end() ){
      Log::info( "Invalid tlev value ({}) found at index {}",
      *found, std::distance(tlevs.begin(), found));
      return false;
    }
    // Make sure tlev values are in increasing order
    auto unsortedStart = std::is_sorted_until( tlevs.begin(), tlevs.end() );
    if( unsortedStart != tlevs.end() ){
      auto dis = std::distance( tlevs.begin(), unsortedStart );
      Log::warning( "tlev values are not in increasing order.");
      Log::info( "tlev value at index {} ({}) > tlev value at index {} ({})",
        dis-1, *(unsortedStart-1), dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
