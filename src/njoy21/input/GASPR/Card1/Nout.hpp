struct Nout : public BROADR::Card1::Nout {
  using Value_t = BROADR::Card1::Nout::Value_t;
  
  static std::string description(){
    return
      "The nout argument specifies the io unit used internally by the\n"
      "Fortran routine and the PENDF-format tape to be output, e.g. setting\n"
      "nout to 21 or -21 implies a pendf tape named 'tape21' should be\n"
      "produced.\n"
      "\n"
      "The signedness of the argument implies the formatting of the tape in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "nout values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to\n"
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
