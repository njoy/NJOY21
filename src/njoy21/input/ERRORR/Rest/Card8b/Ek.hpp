struct Ek {
  using Value_t = std::vector< Quantity< electronVolt > >;
  static std::string name(){ return "ek"; }
  static std::string description(){
    return "The ek parameter specifies the nek+1 energy bin boundaries for\n"
           "the derived cross section covariances, in eV.";
  }
  static bool verify( const Value_t ek ){
    std::vector< Quantity< electronVolt > > used;
    for( auto i : ek ){
// Check for duplicates
      if( std::find( used.begin(), used.end(), i ) != used.end() ){
        Log::error( "Energy bin boundary {} used more than once.", i );
        return false;
      }
// Check for valid values
      if( i <= 0.0*eV ){
        Log::info( "Energy bin boundary value {} is invalid.", i );
        return false;
      }
    }
// Check for ascending order
    auto unsortedStart( ek.begin(), ek.end() );
    if( unosrtedStart != ek.end() ){
      Log::error( "Energy bin boundaries not in ascending order.  {} > {}.",
                                            unsortedStart[-1], *unsortedStart );
      return false;
    }
    return true;
  }
};
