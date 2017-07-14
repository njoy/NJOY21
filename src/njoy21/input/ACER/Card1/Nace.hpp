struct Nace : public argument::common::Nout {

  using Value_t = argument::common::Nout::Value_t;
  
  static std::string name(){ return "nace"; }
  static std::string description(){
    return 
      "The nace argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting nace to\n"
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
      "nace is the main output tape for the ACE-formatted data table.";
  }
  static bool verify( const Value_t v, 
                      const Argument<Nendf>& nendf, 
                      const Argument<Npend>& npend,
                      const Argument<Ngend>& ngend
                      ){

    return ( (v == 0) or( std::abs(v) > 19 && std::abs(v) < 100 ) ) and
        /* Make sure the nace is not equal to other input tape numbers */
        ( std::abs(nendf.value) != std::abs( v ) ) and
        ( std::abs(npend.value) != std::abs( v ) ) and
        ( std::abs(ngend.value) != std::abs( v ) );
  }
};
