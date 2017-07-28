struct Rho {
  using Value_t = std::vector< double >;
  static std::string name(){ return "rho"; }

  static std::string description() {
    return 
        "The rho argument provides the frequency spectra as a function \n"
	"of energy (eV). The frequency spectra should be provided across\n"
	"an interval that is delta-wide (where delta is  Card11 input),\n"
	"and should be given using ni-many points (where ni is a Card11\n"
	"input as well).\n"
	"\n"
	"rho values should be given in the order of increasing eV, but\n"
	"do not have to be in increasing order themselves.";
  }

  static bool verify( const Value_t& rhos,
                      const Argument< LEAPR::Card11::Ni > & ){
    // Make sure all rhos are positive
    auto found = std::find_if( rhos.begin(), rhos.end(),
                               [](auto& a){ return a < 0.0; });
    if ( found != rhos.end() ){
      Log::info( "Negative rho ({}) found at index {}",
                    *found, std::distance(rhos.begin(), found));
      return false;
    } 

    // If we haven't returned false yet...
    return true;
  }
};
