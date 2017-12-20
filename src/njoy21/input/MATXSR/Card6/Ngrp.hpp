struct Ngrp {
  using Value_t = std::vector< int >;
  static std::string name(){ return "ngrp"; }
  static std::string description(){
    return "The ngrp parameter specifies the number of groups for each\n"
           "particle.";
  }
  static bool verify( const Value_t ngrpList, const unsigned int npart ){
    if( ngrpList.size() != npart ) return false;
    auto pos = std::find_if( ngrpList.begin(), ngrpList.end(),
                             []( const int ngrp )->bool{ return ngrp < 0; } );
    if( pos != ngrpList.end() ) return false;
    return true;
  }
};
