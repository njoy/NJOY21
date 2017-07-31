struct Skappa {
  using Value_t = std::vector< decltype( pow( 1.0 * angstrom, Ratio<-1> ) ) >;
  static std::string name(){ return "skappa"; }

  static std::string description() {
    return 
      "The skappa argument gives the kappa values for the pair correlation\n"
      "function S(kappa) (also known as the 'static structure factor'). The\n"
      "kappa values are entered in units of inverse angstroms, and there \n"
      "should be nka-many entries (nka is a Card17 input). All kappa inputs\n"
      "must be positive, and given in increasing order.";
  }

  static bool verify( const Value_t& skappas,
                      const Argument< LEAPR::Card17::Nka > & ){
    // Make sure all skappas are positive
    auto found = std::find_if( skappas.begin(), skappas.end(),
                               [](auto& a){ return a <= 0.0 * pow( 1.0 * angstrom, Ratio<-1> ); });
    if ( found != skappas.end() ){
      Log::info( "Negative skappa ({}) found at index {}",
                    *found, std::distance(skappas.begin(), found));
      return false;
    } 

    // Make sure skappa values are in increasing order
    auto unsortedStart = std::is_sorted_until( skappas.begin(), skappas.end() );
    if( unsortedStart != skappas.end() ){
      auto dis = std::distance( skappas.begin(), unsortedStart );
      Log::warning( "Kappa values are not in increasing order.");
      Log::info( "kappa at index {} ({}) > kappa at index {} ({})",
                   dis-1, unsortedStart[-1], dis, *(unsortedStart));
      return false;
    }

    // If we haven't returned false yet...
    return true;
  }
};
