struct Nout : public argument::common::Nout {
  
  static Value_t defaultValue( const Argument< Nin >& ){ return 0; }
  static std::string description(){
    return argument::common::Nout::description() +
      "\n"
      "The nout for DTFR must be positive valued, meaning coded (e.g. ASCII).\n"
      "The default value is equal to zero, which means no nout file is used.\n"
      "In the case that nout does not equal 0, it must not equal the absolute\n"
      "value of nin.";
  } 
  static bool verify( const Value_t v,
                      const Argument< Nin >& nin ){
    return ( v == 0 or v > 19 ) 
      and  ( v != std::abs(nin.value) ) 
      and  ( v < 100 );
  }
};
