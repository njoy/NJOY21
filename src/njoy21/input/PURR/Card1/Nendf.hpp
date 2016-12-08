struct Nendf {
  using Value_t = argument::common::Nin::Value_t;
  static std::string name(){ return "nendf"; }
  static std::string description(){
    return
      "The nendf argument specifies the io unit used internally by the\n"
      "Fortran routine and the ENDF-format tape to be read in, e.g. setting\n"
      "nendf to 21 or -21 implies a endf tape named 'tape21' is available in\n"
      "the working directory. PURR extracts from the ENDF-formatted tape, \n"
      "resonance parameters from MF=2 and background cross section values \n"
      "from MF=3.\n"
      "\n"
      "The signedness of the argument implies the formatting of the tape in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "nendf values are restricted to an absolute value between 20 and 99,\n"
      "inclusively.";
  }
  
  static bool verify( const Value_t v ){
    return argument::common::Nin::verify(v);
  }
};
