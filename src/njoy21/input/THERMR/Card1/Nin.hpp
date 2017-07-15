struct Nin : public argument::common::Nin {
  
  static bool verify( const Value_t v, const Argument< Nendf >& nendf ){
    return argument::common::Nin::verify(v)
      and ( std::abs(v) != std::abs( nendf.value ) );
  }
};
