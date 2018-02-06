struct Nendf : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  static std::string name(){ return "nendf"; }
  static std::string description(){
    return
      "The nendf argument specifies the io unit used internally by the\n"
      "Fortran routine and the filename to be read in, e.g. setting nendf to\n"
      "21 or -21 implies a file named 'tape21' is available in the working\n"
      "directory.\n"
      "\n"
      "The signedness of the argument implies the formatting of the file in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "nendf values are restricted to an absolute value between 20\n"
      "and 99, inclusively.\n"
      "\n"
      "The nendf argument corresponds to an ENDF-formatted tape (as opposed \n"
      "to PENDF, GENDF, ERROR, etc.)";
  }
  static bool verify( const Value_t v ){
    return argument::common::Nin::verify(v);
  }
}; // struct Nendf

