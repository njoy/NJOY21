struct Ow {
  using Value_t = std::vector< double >;
  static std::string name(){ return "ow"; }

  static std::string description() {
    return 
      "The ow argument gives the weightings of the nd discrete\n"
      "oscillators (where nd is a card14 input).\n"
      "\n"
      "ow values should be given such that the oscillators they correspond\n"
      "to are in the order of increasing eV, although the ow values\n"
      "themselves do not have to be in increasing order themselves.\n"
      "\n"
      "Choice of discrete oscillators must be such that:\n"
      "   wt + ws + ( w_1 + w_2 + ... + w_nd ) = 1   \n"
      "where wt is the translational weight (twt from Card13), ws is the\n"
      "weight for solid type law (tbeta from Card13), and each w_i is a \n"
      "component of the ow input";

  }

  static bool verify( const Value_t& ows,
	              const Argument< LEAPR::Card14::Nd > &,
		      const Argument< LEAPR::Card13::Twt >& twt,
                      const Argument< LEAPR::Card13::Tbeta > & tbeta ){
    // Make sure all ows are positive
    auto found = std::find_if( ows.begin(), ows.end(),
                               [](auto& a){ return a < 0.0; });
    if ( found != ows.end() ){
      Log::info( "Negative ow ({}) found at index {}",
                    *found, std::distance(ows.begin(), found));
      return false;
    } 
    auto sum = std::accumulate( ows.begin(), ows.end(), 0.0 );
    return sum + twt.value + tbeta.value == 1.0;
  }
};
