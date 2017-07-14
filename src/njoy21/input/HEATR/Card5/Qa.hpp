struct Qa {
  using Value_t = std::vector< Quantity<ElectronVolts> >;
  static std::string name(){ return "qa"; }
  static std::string description(){
    return
      "The qa input values are a set of q values used to change the existing\n"
      "values in for a given reaction. Each q value corresponds with an mt\n"
      "value from the Card4 mta input.\n"
      "\n"
      "The q values should not be comma separated, and there should be\n"
      "nqa entries in Card5 (nqa is an input from Card3).";
  }

  static bool verify( const Value_t& qa, 
                      const Argument< HEATR::Card2::Nqa >& ){
    for( auto q : qa ){
      if( 99e6 * electronVolts < q or -99e6 * electronVolts > q ){
        Log::info( "\nq value: {}", q );
        Log::warning("abs( q values ) > 99e6 will use card5a qbar entry\n" );
      }
    }
    return true;
  }    
};
