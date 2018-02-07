struct Ek {
  using Value_t = std::vector< Quantity< eV > >;
  static std::string name(){ return "ek"; }
  static std::string description(){
    return "The ek parameter specifies the nek+1 derived cross section energy\n"
           "bounds in eV.";
  }
  static bool verify( const Value_t ek ){
    if( ek.at( 0 ) < 0.0*dimwits::eV ) return false;
    auto unsortedStart = std::is_sorted_until( ek.begin(), ek.end() );
    if( unsortedStart != ek.end() ){
      Log::error( "Energy boundaries must be in ascending order." );
      Log::info( "Energy bound {} > {}.", unsortedStart[-1], *unsortedStart );
    }
    return true;
  }
};
