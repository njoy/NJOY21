struct Nendf {
  using Value_t = int;
  static std::string name(){ return "nin"; }
  static std::string description(){
    return "The nin parameter specifies the unit for the endf tape.";
  }
  static bool verify( const Value_t nendf ){
    return ( nendf == 999 or ( std::abs( nendf ) > 19 and
                               std::abs( nendf ) < 100 ) );
};
