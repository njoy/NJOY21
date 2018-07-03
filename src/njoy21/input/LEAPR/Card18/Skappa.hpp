struct Skappa {
  using Value_t = std::vector< decltype( pow( 1.0 * angstrom, Ratio<-1> ) ) >;
  static std::string name(){ return "skappa"; }

  static std::string description() {
    return 
      "The skappa argument gives the kappa values for the pair correlation\n"
      "function S(kappa) (also known as the 'static structure factor'). The\n"
      "kappa values are entered in units of inverse angstroms, and there \n"
      "should be nka-many entries (nka is a Card17 input). All kappa inputs\n"
      "must be positive, and given in increasing order of energy, but not in\n"
      "increasing order themselves.";
  }

  static bool verify( const Value_t& skappas,
                      const Argument< LEAPR::Card17::Nka > & ){
    // Make sure first skappa is positive
    if ( skappas[0] <= 0.0 * pow( 1.0 * angstrom, Ratio<-1> ) ){
      Log::info( "Negative skappa found" );
      return false;
    } 

    // If we haven't returned false yet...
    return true;
  }
};
