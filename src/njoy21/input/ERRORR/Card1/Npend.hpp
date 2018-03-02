struct Npend {
  using Value_t = int;
  static std::string name(){ return "npend"; }
  static std::string description(){
    return "The npend parameter specifies the unit for the pendf tape.";
  }
  static bool verify( const Value_t npend, const int nendf ){
    return ( npend == 0 or ( argument::common::Nin::verify( npend ) and
             std::abs( npend ) != std::abs( nendf ) ) );
  }
};
