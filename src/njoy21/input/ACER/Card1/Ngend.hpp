struct Ngend : public argument::common::Nout {

  using Value_t = argument::common::Nout::Value_t;
  
  static std::string name(){ return "ngend"; }
  static std::string description(){
    return 
      "The ngend argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting ngend to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "nace values are restricted to an absolute value in the range [20, 99]."
      "\n"
      "The ngend tape is only needed for input if the old 30x20 photon \n"
      "production matrix is to be constructed; otherwise, set it to zero. In\n"
      "addition, ngend is used for plotting output (if available) when one of\n"
      "the print or edit options is selected (see iopt=7); set it to zero to\n"
      "suppress plotting output.";
  }
  static bool verify( const Value_t v, 
                      const Argument<Nendf>& nendf, 
                      const Argument<Npend>& npend ){

    return ( (v == 0) or argument::common::Nin::verify( v ) ) and
        ( Npend::verify(npend.value, nendf) ) and // nendf and npend are valid 
        /* Make sure the ngend is not equal to other input tape numbers */
        ( std::abs(nendf.value) != std::abs( v ) ) and
        ( std::abs(npend.value) != std::abs( v ) );
  }
};
