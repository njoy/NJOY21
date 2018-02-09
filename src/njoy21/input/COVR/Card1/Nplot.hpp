struct Nplot {
  using Value_t = int;
  
  static std::string name(){ return "nplot"; }
  static std::string description(){ 
    return
      "nplot is the output plot info for the viewr module. It will contain\n"
      "the lines that viewr will use to prepare the postscript plots of the\n"
      "covr results. It is restricted to either have an absolute value\n"
      "between 20 and 99, inclusively, or have a value of zero, which means\n"
      "that the nplot option is not used. nplot has a default value of 0.";
  } 
  
  static Value_t defaultValue( const Argument<Nin>&,
                               const Argument<Nout>& ){
    return 0; 
  }
  static bool verify( const Value_t nplot, 
                      const Argument<Nin>& nin,
                      const Argument<Nout>& nout ){
    if( nplot == 0 ){ return true; }
    

    return ( std::abs( nplot ) > 19 and std::abs( nplot ) < 100 ) 
      and ( std::abs(nin.value)   != std::abs( nplot ) )
      and ( std::abs(nout.value)  != std::abs( nplot ) );
  }
};
