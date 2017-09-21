struct Nplt0 : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  static std::string name(){ return "nplt0"; }
  static std::string description(){
    return
      "The nplt0 argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename for input plot commands, e.g.\n"
      "setting nplt0 to 21 or -21 implies a file named 'tape21' is available\n"
      "in the working directory.\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "Typically, nplt0 values are restricted to an absolute value between 20\n"
      "and 99, inclusively.  The default value, 0, is also allowed.  As\n"
      "usual, the value for nplt0 cannot be the same as nplt.";
  }
  static int defaultValue( const Argument< Nplt >& ) { return 0; }
  static bool verify( const Value_t v, const Argument< Nplt >& nplt ){
    return v == 0 || argument::common::Nout::verify(v, nplt);
  }
};
