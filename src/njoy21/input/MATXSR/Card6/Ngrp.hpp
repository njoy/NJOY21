struct Ngrp {
  using Value_t = int;
  static std::string name(){ return "ngrp"; }
  static std::string description(){
    return "The ngrp parameter specifies the number of groups for each\n"
           "particle.";
  }
  static bool verify( const Value_t ngrp ){ return ngrp >= 0; }
};
