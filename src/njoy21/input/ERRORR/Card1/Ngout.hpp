struct Ngout {
  using Value_t = int;
  static std::string name(){ return "ngout"; }
  static std::string description(){
    return "The ngout parameter specifies the unit for input group cross\n"
           "section tape. The default value is zero.";
  }
  static Value_t defaultValue( const int, const int ){ return 0; }
  static bool verify( const int ngout, const int nendf, const int npend ){
    return ( argument::common::Nin::verify( ngout ) and
             std::abs( ngout ) != std::abs( nendf ) and
             std::abs( ngout ) != std::abs( npend ) );
  }
};
