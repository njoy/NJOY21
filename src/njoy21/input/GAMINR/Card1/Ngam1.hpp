struct Ngam1{
  using Value_t = int;

  static std::string description(){
    return
      "The ngam1 argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting ngam1 to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output. The normal mode for GAMINR is to use ngam1=0; however it is\n"
      "sometimes convenient to add a new material or raction to an existing\n"
      "GENDF tape.\n"
      "\n"
      "When the ngam1 argument is specified, NJOY will copy this tape to \n"
      "ngam2 and append the new GENDF tape to ngam2."
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "A value of 0 is allowed and is the normal mode. When non-zero ngam1\n"
      "values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to have the same signedness as\n"
      "(and different absolute value than) the corresponding nendf argument.\n";
  }
  static std::string name(){
    return "Ngam1";
  }

  static int defaultValue( const Argument< Nendf >&,
                           const Argument< Npend >&){ return 0; }
  static bool verify( const Value_t v,
                      const Argument< Nendf >& nendf,
                      const Argument< Npend >& npend){
    return (v == 0) or (
             ( argument::common::Nout::verify(v, nendf) ) and
             ( std::abs( npend.value ) != std::abs( v ) ) );
  }
};
