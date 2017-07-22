struct Ndir : public argument::common::Nout {

  using Value_t = argument::common::Nout::Value_t;
  
  static std::string name(){ return "ndir"; }
  static std::string description(){
    return 
      "The ndir argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting ndir to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "ndir values are restricted to an absolute value in the range [20, 99]."
      "\n"
      "ndir contains the xsdir entry for the ACE file.";
  }
  static bool verify( const Value_t v, 
                      const Argument<Nendf>& nendf, 
                      const Argument<Npend>& npend,
                      const Argument<Ngend>& ngend,
                      const Argument<Nace>& nace
                      ){

    return argument::common::Nin::verify( v ) and
        /* Make sure the ndir is not equal to other input tape numbers */
        ( std::abs(nendf.value) != std::abs( v ) ) and
        ( std::abs(npend.value) != std::abs( v ) ) and
        ( std::abs(ngend.value) != std::abs( v ) ) and
        ( std::abs(nace.value) != std::abs( v ) );
  }
};
