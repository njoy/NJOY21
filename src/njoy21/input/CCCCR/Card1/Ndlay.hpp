struct Ndlay{
  using Value_t = int;
  static std::string name(){ return "ndlay"; }
  static std::string description(){
    return "The ndlay parameter specifies the outlet unit for dlayxs.  If\n"
           "set to 0, no dlayxs input will be read.";
  }
  static Value_t defaultValue( const Value_t, const Value_t, const Value_t ){
    return 0;
  }
  static bool verify( const Value_t ndlay, const Value_t nbrks,
                      const Value_t nisot, const Value_t nin ){
    return ( ndlay == 0 or ( std::abs( ndlay ) != std::abs( nbrks ) and
                             std::abs( ndlay ) != std::abs( nisot ) and
                             std::abs( ndlay ) != std::abs( nin ) and
                             argument::common::Nin::verify( ndlay ) ) );
  }
};
