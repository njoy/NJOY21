struct Dap {
  using Value_t = double;
  static std::string name(){ return "dap"; }
  static std::string description(){
    return "The dap parameter specifies the user specified scattering radius\n"
           "uncertainty, given as a fraction (i.e. - dap=0.1 means 10%\n"
           "uncertainty in the scattering radius).  The default value is\n"
           "zero.  This variable is only defined for mfcov=33 and if non-zero\n"
           "will be used in lieu of any data that might have been read from\n"
           "the nendf tape.";
  }
  static Value_t defaultValue( const int ){ return 0.0; }
  static bool verify( const Value_t dap, const int mfcov ){
    return ( mfcov != 33 or ( dap >= 0.0 and dap <= 1.0 ) );
  }
};
