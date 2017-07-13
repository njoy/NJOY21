struct Nin : argument::common::Nin {
  static std::string description(){
    return
      argument::common::Nin::description() + 
      "\n\n"
      "For HEATR in particular, the nin input cannot have the same absolute\n"
      "value that the nendf input has.";
  }

  static bool verify( const Value_t v, const Argument< Nendf >& nendf ){
    return argument::common::Nin::verify(v)
      and ( std::abs(v) != std::abs( nendf.value ) );
  }
};
