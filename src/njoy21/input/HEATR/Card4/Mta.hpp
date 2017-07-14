struct Mta {
  using Value_t = std::vector<int>;
  static std::string name(){ return "mta"; }
  static std::string description(){
    return
      "The mta input values are a set of mt numbers for user-provided q\n"
      "values. These mt inputs correspond to the q values provided on Card5,\n"
      "and the addition of an mt / q value pair can be used to change an\n"
      "existing reaction's q value.\n"
      "\n"
      "The mt values should not be comma separated, and there should be\n"
      "nqa entries in Card4 (nqa is an input from Card3).";
  }

  static bool verify( const Value_t& mta, 
                      const Argument< HEATR::Card2::Nqa >& ){
    for( int mt : mta ){
      if( mt < 1 or mt > 999 ){
        Log::info( "mt value {} is out of range", mt );
	return false;
      }
    }
    return true;
  }    
};
