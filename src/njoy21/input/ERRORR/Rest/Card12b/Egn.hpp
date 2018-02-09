struct Egn {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "egn"; }
  static std::string description(){
    return "The egn parameter specifies the energy bin boundaries for the\n"
           "user-defined group structure (as specified by ign = 1 or 19.";
  }
  static bool verify( const Value_t egn ){
    if( egn.front() < 0.0*electronVolt ) return false;
    auto unsortedStart = std::is_sorted_until( egn.begin(), egn.end() );

    if( unsortedStart != egn.end() ){
      Log::error( "Energy boundary bin values not in ascending order.  {} > {}",
                  unsortedStart[-1], *unsortedStart );
      return false;
    }

    return true;
  }
};
