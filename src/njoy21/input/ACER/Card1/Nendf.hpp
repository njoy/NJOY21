struct Nendf : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  
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
      "ACER uses the information from the nendf tape for angle, energy, \n"
      "energy-angle, and photon emission distribitons.\n"
      "\n"
      "Note that the nendf tape specifies an ENDF input (as opposed to an\n"
      "PENDF, or GENDF input.";
  }
  static bool verify( const Value_t v ){
    return ( v == 0 ) or argument::common::Nin::verify(v);
  }
}; // struct Nendf


