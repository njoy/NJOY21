struct Npend : public argument::common::Nin {
  
  using Value_t = argument::common::Nin::Value_t;
  
  static std::string name(){ return "npend"; }
  static std::string description(){
    return
      "The npend argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be output, e.g. setting npend to\n"
      "21 or -21 specifies a file named 'tape21' is will be used for the\n"
      "output\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted output i.e.\n"
      "ascii text files. Negative values indicate unformatted output i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "npend values are restricted to an absolute value between 20 and 99,\n"
      "inclusively, and are required to have the same signedness as\n"
      "(and different absolute value than) the corresponding nendf argument.";
  }

  static bool verify( const Value_t v, const Argument<Nendf>& nendf ){
    return argument::common::Nin::verify( v, nendf );
  }
};


