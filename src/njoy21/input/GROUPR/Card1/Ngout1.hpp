struct Ngout1 : public argument::common::Nout {
  using Value_t = argument::common::Nout::Value_t;
  static std::string name(){ return "ngout1"; }

  static std::string description(){
    return
      "The ngout1 argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting ngout1 to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "ngout1 values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to have the same signedness as\n"
      "(and different absolute value than) the corresponding nendf argument.\n"
      "\n"
      "When the ngout1 argument is specified, NJOY will copy this tape to \n"
      "ngout2 and append the new GENDF tape to ngout2.";
  }

  static Value_t defaultValue( const Argument< Nendf >&,
                               const Argument< Npend >& ) { return 0; }

  static bool verify( const Value_t v, 
                     const Argument< Nendf >& nendf,
                     const Argument< Npend >& npend
                     ){
    return argument::common::Nin::verify( v ) and
        ( Npend::verify( npend.value, nendf ) ) and
        /* Make sure the ngout1 is not equal to other input tape numbers */
        ( std::abs( nendf.value ) != std::abs( v ) ) and
        ( std::abs( npend.value ) != std::abs( v ) );
  }
};
