struct Oe {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "oe"; }

  static std::string description() {
    return 
        "The oe argument gives the energies (eV) of the nd discrete\n"
	"oscillators (where nd is a card14 input).\n"
	"\n"
	"oe values should be given in the order of increasing eV, but\n"
	"do not have to be in increasing order themselves.";
  }

  static bool verify( const Value_t& oes,
                      const Argument< LEAPR::Card14::Nd > & ){
    // Make sure all oes are positive
    auto found = std::find_if( oes.begin(), oes.end(),
                               [](auto& a){ return a < 0.0 * electronVolts; });
    if ( found != oes.end() ){
      Log::info( "Negative oe ({}) found at index {}",
                    *found, std::distance(oes.begin(), found));
      return false;
    } 

    // Make sure oe values are in increasing order
    auto unsortedStart = std::is_sorted_until( oes.begin(), oes.end() );
    if( unsortedStart != oes.end() ){
      auto dis = std::distance( oes.begin(), unsortedStart );
      Log::warning( "Oscillator Energies are not in increasing order.");
      Log::info( "Energy at index {} ({}) > energy at index {} ({})",
                   dis-1, unsortedStart[-1], dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
