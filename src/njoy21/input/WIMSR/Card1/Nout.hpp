struct Nout {
  using Value_t = int;
  static std::string name(){ return "nout"; }
  static std::string description(){
    return "The nout argument specifies the io unit used internally by the \n"
           "Fortran routine and the filename to be output, e.g. setting nout\n"
           "to 21 specifies a file named 'tape21' will be sued for the\n"
           "output.\n"
           "The available values are all integers between 20 and 99,\n"
           "inclusively.  The value of the nout parameter cannot be the same\n"
           "as the absolute value of the ngendf paramter.";
  }
  static bool verify( const Value_t nout, const Value_t ngendf ){
    return ( nout > 0 and std::abs( nout ) != std::abs( ngendf ) and 
             argument::common::nin::verify( nout ) );
  }
};
