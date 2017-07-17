struct Nplot {
  using Value_t = int;
  static std::string name(){ return "nplot"; }
  
  static std::string description(){
    return
      "The nplot argument specifies the io unit used internally by the\n"
      "Fortran routine and the VIEWR input file to be output, e.g. setting\n"
      "nout to 21 or -21 implies a VIEWR input file named 'tape21' should be\n"
      "produced.\n"
      "\n"
      "The signedness of the argument implies the formatting of the tape in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "If the nplot option is used, then the nploy value are restricted to\n"
      "have an absolute value between 20 and 99, inclusively, and are\n"
      "required to have an absolute value distinct from the corresponding\n"
      "nendf, nin, and nout values. An nplot value of 0 indicates that the\n"
      "nplot option is not going to be used.\n"
      "\n"
      "nplot has a default value of 0.";
  }

  static Value_t defaultValue( const Argument< Nendf >&,
			       const Argument< Nin >&,
			       const Argument< Nout >& ){ return 0; }
  
  static bool verify( const Value_t v,
		      const Argument< Nendf >& nendf,
		      const Argument< Nin >& nin,
		      const Argument< Nout >& nout ){
    if( v == 0 ){ return true; }
    const auto absv = std::abs(v);
    return argument::common::Nout::verify( v )
      and ( absv != std::abs( nendf.value ) )
      and ( absv != std::abs( nin.value ) )
      and ( absv != std::abs( nout.value ) );
  }
};
