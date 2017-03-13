struct Nendf : public BROADR::Card1::Nendf {
  using Value_t = BROADR::Card1::Nendf::Value_t;
  static std::string description(){
    return
      "The nendf argument specifies the io unit used internally by the\n"
      "Fortran routine and the ENDF-format tape to be read in, e.g. setting\n"
      "nendf to 21 or -21 implies a endf tape named 'tape21' is available in\n"
      "the working directory. HEATR refers to the ENDF-format tape specified\n"
      "by the nendf argument to determine whether photon production cross-\n"
      "section and yields are available (ENDF Files 13 and 12, repectively),\n"
      "and whether fission need be considered (i.e. some combination of ENDF\n"
      "Section 18, 19, or 458 are present).\n"
      "\n"
      "The signedness of the argument implies the formatting of the tape in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "nendf values are restricted to an absolute value between 20 and 99,\n"
      "inclusively.";
  }
};
