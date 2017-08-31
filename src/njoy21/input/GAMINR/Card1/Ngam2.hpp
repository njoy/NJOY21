struct Ngam2{
  using Value_t = int;

  static std::string description(){
    return
      "The ngam2 argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting ngam2 to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to have the same signedness as\n"
      "(and different absolute value than) the corresponding nendf argument.\n"
      "\n"
      "When the ngam1 argument is specified, NJOY will copy this tape to \n"
      "ngam2 and append the new GENDF tape to ngam2. Otherwise, (when\n"
      "ngam1=0) the GENDF tape is written to ngam2.";
  }
  static std::string name(){
    return "Ngam2";
  }

  static int defaultValue( const Argument< Nendf >&,
                           const Argument< Npend >&,
                           const Argument< Ngam1 >&){ return 0; }
  static bool verify( const Value_t v,
                      const Argument< Nendf >& nendf,
                      const Argument< Npend >& npend,
                      const Argument< Ngam1 >& ngam1){
    return (v == 0) or (
             ( argument::common::Nout::verify(v, nendf)) and
             ( std::abs( npend.value ) != std::abs( v ) ) and
             ( std::abs( ngam1.value ) != std::abs( v ) ) and
             ( v*nendf.value > 0 ) and
             ( v*ngam1.value >= 0 ) );
  }
};
