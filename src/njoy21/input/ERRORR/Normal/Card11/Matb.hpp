struct Matb {
  using Value_t = int;
  static std::string name(){ return "matb"; }
  static std::string description(){
    return "The matb parameter specifies the material for which the reaction\n"
           "will be replaced by the materal/MT specified later in this card.";
  }
  static bool verify( const Value_t matb ){
    return ( argument::common::Matd::verify( std::abs( matb ) ) or matb == 0 );
  }
};
