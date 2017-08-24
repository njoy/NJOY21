struct Nendf : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;

  static std::string name(){
    return "Nendf";
  }
  static std::string description(){
    return
      "The nendf argument specifies the io unit used internally by the\n"
      "Fortran routine and the ENDF filename to be read in, e.g. setting\n"
      " nendf to 21 or -21 implies a file named 'tape21' is available in\n"
      " the working directory.\n\n"
      "The sign of the argument implies the formatting of the file in\n"
      "question.  Positive argument values indicate formatted input i.e.\n"
      "ascii text files.  Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary.\n\n"
      "Typically, nendf values are restricted to an absolute value between\n"
      "20 and 99, inclusively.";
  }
};
