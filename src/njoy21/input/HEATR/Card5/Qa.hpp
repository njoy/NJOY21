struct Qa {
  using Value_t = std::vector< Quantity<ElectronVolts> >;
  static std::string name(){ return "qa"; }
  static std::string description(){
    return
      "The qa input values are a set of user-provided replacement  q values\n"
      "for a given reaction. Each q value corresponds with an mt number from\n"
      "the Card4 mta input. Any q value with an absolute value greater than\n"
      "or equal to 99 MeV requires a qbar (Card5a) entry.\n"
      "\n"
      "The q values should not be comma separated, and there should be\n"
      "nqa entries in Card5 (nqa is an input from Card3).";
  }

  static bool verify( const Value_t&, 
                      const Argument< HEATR::Card2::Nqa >& ){
    return true;
  }    
};
