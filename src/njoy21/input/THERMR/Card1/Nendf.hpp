struct Nendf {
  using Value_t = int;
  static std::string name(){ return "nendf"; }
  static std::string description(){
    return
      "The nendf argument specifies the io unit used internally by the\n"
      "Fortran routine and the ENDF-format tape to be read in, e.g. setting\n"
      "nendf to 21 or -21 implies a endf tape named 'tape21' is available in\n"
      "the working directory. BROADR extracts values for the average number\n"
      "of neutrons emitted from thermal fission from this tape.\n"
      "\n"
      "The signedness of the argument implies the formatting of the tape in\n"
      "question. Positive argument values indicate formatted input i.e.\n"
      "ascii text files. Negative values indicate unformatted input i.e.\n"
      "Fortran-style block binary\n"
      "\n"
      "For thermr in particular, the nendf argument provides an endf\n"
      "file that corresponds to an MF (endf file label) = 7 (thermal \n"
      "scattering).\n"
      "\n"
      "nendf values are restricted to equal either 0, some integer with\n"
      "an absolute value between 20 and 99, inclusively. A value of 0\n"
      "indicates that no endf tape will be provided.";
  }
  
  static bool verify( const Value_t v ){
    return ( argument::common::Nin::verify(v) ) or ( v == 0 );
  }
};
