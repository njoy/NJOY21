struct Ngrp {
  using Value_t = std::vector< int >;
  static std::string name(){ return "ngrp"; }
  static std::string description(){
    return "The ngrp parameter specifies the number of groups for each\n"
           "particle.";
  }
  static bool verify( const Value_t ngrpList, const unsigned int npart ){
    if( ngrpList.size() != npart ) return false;
    for( auto ngrp : ngrpList ){
      if( ngrp < 0 ) return false;
    }
    return true;
  }
};
