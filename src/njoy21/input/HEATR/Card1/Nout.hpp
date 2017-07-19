struct Nout : argument::common::Nout {
  static std::string description(){
    return
      argument::common::Nout::description() +
      "\n\n"
      "For HEATR in particular, the nout input is is required to:\n"
      " + have an absolute value distinct from the corresponding nendf value\n"
      " + have a value distinct from the corresponding nin value\n"
      " + share signedness with the corresponding nin value";
  }
  
  static bool verify( const Value_t v,
		      const Argument< Nendf >& nendf,
		      const Argument< Nin >& nin ){
    return argument::common::Nout::verify( v, nin )
      and ( std::abs(v) != std::abs( nendf.value ) );
  }
};
