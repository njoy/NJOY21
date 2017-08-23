struct Ngout2 : public argument::common::Nout {
  using Value_t = argument::common::Nout::Value_t;
  static std::string name(){ return "ngout2"; }

  static std::string description(){
    return
      "The ngout2 argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting ngout2 to\n"
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
      "When the ngout1 argument is specified, NJOY will copy this tape to \n"
      "ngout2 and append the new GENDF tape to ngout2. Otherwise, (when\n"
      "ngout1=0) the GENDF tape is written to ngout2.";
  }

  template < typename Nin >
  static bool verify( const Value_t v, 
                     const Nin& nendf,
                     const Nin& npend,
                     const Nin& ngout1
                     ){
    return ( argument::common::Nout::verify( v, nendf ) ) and
        /* Make sure the ngout2 is not equal to other input tape numbers */
        ( std::abs( npend.value ) != std::abs( v ) ) and
        ( std::abs( ngout1.value ) != std::abs( v ) );
  }
};
