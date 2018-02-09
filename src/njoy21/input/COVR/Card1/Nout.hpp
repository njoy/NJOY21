struct Nout : argument::common::Nout {

  static Value_t defaultValue( const Argument< Nin > ){ return 0; }
  static bool verify( const Value_t v, const Argument< Nin >& nin ){
    return ( v == 0 ) or 
	   ( argument::common::Nin::verify( v ) and 
	     std::abs( v ) != std::abs( nin.value ) );
  }
};
