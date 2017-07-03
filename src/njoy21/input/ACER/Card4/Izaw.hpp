struct Izaw {
  using Value_t = std::vector< std::pair<int, double> >;
  static std::string name(){ return "iz,aw"; }

  static std::string description(){
    return
        "Pairs of numbers representing iz and aw for photoatomic data.";
  }

  static bool verify( const Value_t& izaw, 
                      const Argument< Card2::Nxtra >& nxtra ){
    // Checking to make sure both IZ and AW are >0
    auto found = std::find_if( izaw.begin(), izaw.end(),
      [](auto& P){ return (P.first < 0) or (P.second < 0); } );

    if( found != izaw.end() ){
      Log::warning( "Negative IZ or AW parameter ({},{}) found at index {}",
                   found->first, found->second, 
                   std::distance( izaw.begin(), found ) );
      return false;
    } else {
      return ( long( izaw.size() ) == nxtra.value );
    }
  }
};
