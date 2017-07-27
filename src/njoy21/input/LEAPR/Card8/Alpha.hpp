struct Alpha {
  using Value_t = std::vector< double >;
  static std::string name(){ return "alpha"; }

  static std::string description() {
    return 
        "The alpha argument provides the alpha values for the scattering law\n"
	"S(a,b) (i.e. dimensionless momentum transfer values for thermal \n"
	"scattering). There should be nalpha many entries, where nalpha is a\n"
	"Card7 input. alpha values should be provided in increasing order.\n"
	"\n"
	"alpha and beta values should be chosen carefully. Too many points\n"
	"makes the evaluation expensive, while too few lead to inaccurate\n"
	"interpolations.";
  }

  static bool verify( const Value_t& alphas,
                      const Argument< LEAPR::Card7::Nalpha > & ){
    // Make sure all alphas are positive
    auto found = std::find_if( alphas.begin(), alphas.end(),
                               [](auto& a){ return a < 0.0; });
    if ( found != alphas.end() ){
      Log::info( "Negative alpha ({}) found at index {}",
                    *found, std::distance(alphas.begin(), found));
      return false;
    } 

    // Make sure alphas are in increasing order
    auto unsortedStart = std::is_sorted_until( alphas.begin(), alphas.end() );
    if( unsortedStart != alphas.end() ){
      auto dis = std::distance( alphas.begin(), unsortedStart );
      Log::warning( "Alphas are not in increasing order.");
      Log::info( "Alpha at index {} ({}) > alpha at index {} ({})",
                   dis-1, unsortedStart[-1], dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
