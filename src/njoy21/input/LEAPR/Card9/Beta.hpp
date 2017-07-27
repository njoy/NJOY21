struct Beta {
  using Value_t = std::vector< double >;
  static std::string name(){ return "beta"; }

  static std::string description() {
    return 
        "The beta argument provides the beta values for the scattering law\n"
	"S(a,b) (i.e. dimensionless energy transfer values for thermal \n"
	"scattering). There should be nbeta many entries, where nbeta is a\n"
	"Card7 input. beta values should be provided in increasing order.\n"
	"\n"
	"alpha and beta values should be chosen carefully. Too many points\n"
	"makes the evaluation expensive, while too few lead to inaccurate\n"
	"interpolations.";
  }

  static bool verify( const Value_t& betas,
                      const Argument< LEAPR::Card7::Nbeta > & ){
    // Make sure all betas are positive
    auto found = std::find_if( betas.begin(), betas.end(),
                               [](auto& a){ return a < 0.0; });
    if ( found != betas.end() ){
      Log::info( "Negative beta ({}) found at index {}",
                    *found, std::distance(betas.begin(), found));
      return false;
    } 

    // Make sure betas are in increasing order
    auto unsortedStart = std::is_sorted_until( betas.begin(), betas.end() );
    if( unsortedStart != betas.end() ){
      auto dis = std::distance( betas.begin(), unsortedStart );
      Log::warning( "Betas are not in increasing order.");
      Log::info( "Beta at index {} ({}) > beta at index {} ({})",
                   dis-1, unsortedStart[-1], dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
