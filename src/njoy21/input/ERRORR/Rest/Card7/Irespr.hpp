struct Irespr {
  using Value_t = int;
  static std::string name(){ return "irespr"; }
  static std::string description(){
    return "The irespr parameter specifies the method of processing for the\n"
           "resonance parameter covariances.  The parameter is only used if\n"
           "(mf=32).  The default value is 1.\n\n"
           "value    meaning\n"
           "-----    -------\n"
           "  0      area sensitivity method\n"
           "  1      1% sensitivity method       ( default )";
  }
  static Value_t defaultValue( const int ){ return 1; }
  static bool verify( const Value_t irespr, const int mfcov ){
    return ( mfcov != 33 or ( irespr == 0 or irespr == 1 ) );
  }
};
