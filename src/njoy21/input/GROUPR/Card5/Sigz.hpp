struct Sigz {
  using Value_t = std::vector< Quantity< Barn > >;
  static std::string name(){ return "sigz"; }

  static std::string description() {
    return
        "The sigz argument is a list of sigma zero cross section values (in\n"
        "barns) that are used to calculate resonance self shielding.\n"
        "\n"
        "Note: the first value will *always* be overwritten with infinity.";
  }
  static bool verify( const Value_t& sigz,
                      const Argument< Card2::Nsigz > & nsigz ){
    auto found = std::find_if( sigz.begin(), sigz.end(),
                               [](auto& E){ return E < 0.0*barn; });

    if ( found != sigz.end() ){
      Log::warning( "Negative sigma zero cross section ({}) found at index {}",
                    *found, std::distance(sigz.begin(), found));
      return false;
    } else {
      return ( long(sigz.size()) == nsigz.value );
    }
  }
};
