struct Nout : public argument::common::Nout {
  
  static bool verify( const Value_t v,
		      const Argument< Nendf >& nendf,
		      const Argument< Nin >& nin ){
    return argument::common::Nin::verify( v )
      && ( std::abs(v) != std::abs( nendf.value ) )
      && ( std::abs(v) != std::abs( nin.value   ) );
  }
};
