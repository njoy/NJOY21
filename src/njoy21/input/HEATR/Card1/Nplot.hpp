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
      "nplot values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to\n"
      " + have an absolute value distinct from the corresponding nendf value\n"
      " + have an absolute value distinct from the corresponding nin value\n"
      " + have an absolute value distinct from the corresponding nout value";
  }

  static Value_t defaultValue( const Argument< Nendf >&,
			       const Argument< Nin >&,
			       const Argument< Nout >& ){ return 0; }
  
  static bool verify( const Value_t v,
		      const Argument< Nendf >& nendf,
		      const Argument< Nin >& nin,
		      const Argument< Nout >& nout ){
    const auto absv = std::abs(v);
    return argument::common::Nout::verify( v )
      and ( absv != std::abs( nendf.value ) )
      and ( absv != std::abs( nin.value ) )
      and ( absv != std::abs( nout.value ) );
  }
};
