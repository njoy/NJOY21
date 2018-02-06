struct Nplt {
  using Value_t = argument::common::Nin::Value_t;
  static std::string name(){ return "nplt"; }
  static std::string description(){
    return
      "The nplt argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename for output plot commands, e.g.\n"
      "setting nplt to 21 or -21 implies a file named 'tape21' is available\n"
      "in the working directory.\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "Typically, nplt values are restricted to an absolute value between 20\n"
      "and 99, inclusively.";
  }
  static bool verify( const Value_t v ){
    return argument::common::Nin::verify(v);
  }
};
