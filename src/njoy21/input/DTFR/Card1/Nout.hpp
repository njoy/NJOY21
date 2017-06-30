struct Nout : public argument::common::Nout {
  using Value_t = argument::common::Nout::Value_t;
  
  static Value_t defaultValue(const Argument< Nin >&){ return 0; }
  static std::string description(){
    return argument::common::Nout::description() +
      "\n"
      "The nout for DTFR must be positive valued, or coded (e.g. ASCII).";
  } 
  static bool verify( const Value_t v,
		      const Argument< Nin >& nin ){
    return argument::common::Nout::verify( v, nin );
  }
};
