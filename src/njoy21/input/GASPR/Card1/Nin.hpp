struct Nin : public BROADR::Card1::Nin {
  using Value_t = BROADR::Card1::Nin::Value_t;
  static std::string description(){
    return
      "The nin argument specifies the io unit used internally by the\n"
      "Fortran routine and the PENDF-format tape to be read in, e.g. setting\n"
      "nin to 21 or -21 implies a pendf tape named 'tape21' is available in\n"
      "the working directory.\n"
      "\n"
      "The signedness of the argument implies the formatting of the tape in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "nin values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to have an absolute value distinct from\n"
      "the corresponding nendf value.";
  }

  static bool verify( const Value_t v, const Argument< Nendf >& nendf ){
    return argument::common::Nin::verify(v)
           and ( std::abs(v) != std::abs( nendf.value ) );
  }
};
