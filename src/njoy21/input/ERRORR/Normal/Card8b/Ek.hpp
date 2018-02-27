struct Ek {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "ek"; }
  static std::string description(){
    return "The ek parameter specifies the nek+1 energy bin boundaries for\n"
           "the derived cross section covariances, in eV.";
  }
  static bool verify( const Value_t ek, const int ){
    std::vector< Quantity< ElectronVolt > > used;
    if( ek.size() == 0 ){
      Log::error( "No energy bins were provided." );
      return false;
    }
    for( auto i : ek ){
// Check for duplicates
      if( std::find( used.begin(), used.end(), i ) != used.end() ){
        Log::error( "Energy bin boundary {} used more than once.", i );
        return false;
      }
// Check for valid values
      if( i <= 0.0*electronVolt ){
        Log::info( "Energy bin boundary value {} is invalid.", i );
        return false;
      }
      used.push_back( i );
    }
// Check for ascending order
    auto unsortedStart = std::is_sorted_until( ek.begin(), ek.end() );
    if( unsortedStart != ek.end() ){
      Log::error( "Energy bin boundaries not in ascending order.  {} > {}.",
                                            unsortedStart[-1], *unsortedStart );
      return false;
    }
    return true;
  }
};
