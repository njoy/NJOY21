struct Nin {
  using Value_t = int;
  static std::string name(){ return "nin"; }
  static std::string description(){
    return
      "The nin argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be read in, e.g. setting nin to\n"
      "21 or -21 implies a file named 'tape21' is available in the working\n"
      "directory.\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "Typically, nin values are restricted to an absolute value between 20\n"
      "and 99, inclusively.";
  }
  static bool verify( const Value_t v ){
    return std::abs(v) > 19 && std::abs(v) < 100;
  }
};
