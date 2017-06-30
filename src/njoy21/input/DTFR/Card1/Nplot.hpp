struct Nplot {
  using Value_t = int;
  
  static std::string name(){ return "nplot"; }
  static std::string description(){ 
    return
      "Nplot is the outut plot info for the plotr module. It will contain\n"
      "the lines that VIEWR will use to prepare the postscript plots of the\n"
      "DTFR results. It is restricted to have an absolute value between 20\n"
      "and 99, inclusively, and has a default value of 0.";
  } 
  
  static Value_t defaultValue( const Argument<Nin>&,
                               const Argument<Nout>&,
                               const Argument<Npend>& ){ 
    return 0; 
  }
  static bool verify( const Value_t v, 
                      const Argument<Nin>& nin,
                      const Argument<Nout>& nout,
                      const Argument<Npend>& npend ){

    return argument::common::Nin::verify( v )
      && ( std::abs(nin.value)   != std::abs( v ) )
      && ( std::abs(nout.value)  != std::abs( v ) )
      && ( std::abs(npend.value) != std::abs( v ) );
  }
};
