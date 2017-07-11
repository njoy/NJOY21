struct Npend : public argument::common::Nin {
  
  using Value_t = int;

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
      "(and different absolute value than) the corresponding nendf argument.\n"
      "\n"
      "The npend file should should be the same PENDF tape that was used in \n"
      "GROUPR where nin was made. Npend if only necessary if plots are\n"
      "requested.\n"
      "\n"
      "npend has a default value of 0, which means that the npend/nplot\n"
      "options are not used.";
      ;
  }

  static Value_t defaultValue( const Argument<DTFR::Card1::Nin>&, 
                               const Argument<DTFR::Card1::Nout>& ){ 
    return 0; 
  }
  static bool verify( const Value_t v, 
                      const Argument<DTFR::Card1::Nin>& nin,
                      const Argument<DTFR::Card1::Nout>& nout ){
    if ( v == 0 ){ 
      // npend cannot equal zero if nout equals zero
      if ( nout.value == 0 ){ return false; }
      else { return true; }
    }
    else {
      // If npend is not zero, continue with standard checks
      return argument::common::Nin::verify( v )
        and ( std::abs(nin.value)  != std::abs( v ) )
        and ( std::abs(nout.value) != std::abs( v ) );
    }  
  }
};


