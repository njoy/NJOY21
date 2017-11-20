struct Nout {
  using Value_t = int;
  static std::string name(){ return "nout"; }
  static std::string description(){
    return
      "The nout argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting nout to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "Typically, nout values are restricted to an absolute value between 20\n"
      "and 99, inclusively, and are required to have the same signedness as\n"
      "(and different absolute value than) the corresponding nin argument.";
  }

  static bool verify( const Value_t v ){
    return std::abs(v) > 19 && std::abs(v) < 100;
  }

  template< typename Nin >
  static bool verify( const Value_t v, const Nin& nin ){
    return verify(v)
      && ( nin.value * v > 0 ) && ( std::abs(nin.value) != std::abs(v) );
  }
};
