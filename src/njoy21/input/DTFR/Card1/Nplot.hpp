struct Nplot {
  using Value_t = int;
  
  static std::string name(){ return "nplot"; }
  static std::string description(){ 
    return
      "nplot is the output plot info for the plotr module. It will contain\n"
      "the lines that VIEWR will use to prepare the postscript plots of the\n"
      "DTFR results. It is restricted to either have an absolute value\n"
      "between 20 and 99, inclusively, or have a value of zero, which means\n"
      "that the nplot option is not used. nplot has a default value of 0.\n"
      "\n"
      "If npend equals 0, then nplot must also equal 0. Similarly, if\n"
      "npend does not equal 0, then neither can nplot.\n"
      "\n"
      "If nout equals 0, then neither npend nor nplot may equal 0, since\n"
      "there must always be a way to retrieve the output";
  } 
  
  static Value_t defaultValue( const Argument<Nin>&,
                               const Argument<Nout>&,
                               const Argument<Npend>& ){ 
    return 0; 
  }
  static bool verify( const Value_t nplot, 
                      const Argument<Nin>& nin,
                      const Argument<Nout>& nout,
                      const Argument<Npend>& npend ){

    if ( nplot == 0 ){
      if ( npend.value == 0 and nout.value != 0 ){ return true; }
      else { return false; }
    }
    else {
      return ( std::abs( nplot ) > 19 and std::abs( nplot ) < 100 ) 
        and ( std::abs(nin.value)   != std::abs( nplot ) )
        and ( std::abs(nout.value)  != std::abs( nplot ) )
        and ( std::abs(npend.value) != std::abs( nplot ) );
    }
  }
};
