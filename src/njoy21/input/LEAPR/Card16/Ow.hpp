struct Ow {
  using Value_t = std::vector< double >;
  static std::string name(){ return "ow"; }

  static std::string description() {
    return 
        "The ow argument gives the energies (eV) of the nd discrete\n"
	"oscillators (where nd is a card14 input).\n"
	"\n"
	"ow values should be given in the order of increasing eV, but\n"
	"do not have to be in increasing order themselves.";
  }

  static bool verify( const Value_t& ows,
                      const Argument< LEAPR::Card14::Nd > & ){
    // Make sure all ows are positive
    auto found = std::find_if( ows.begin(), ows.end(),
                               [](auto& a){ return a < 0.0; });
    if ( found != ows.end() ){
      Log::info( "Negative ow ({}) found at index {}",
                    *found, std::distance(ows.begin(), found));
      return false;
    } 

    // If we haven't returned false yet...
    return true;
  }
};
