struct Ifissp {
  using Value_t = int;
  static std::string name(){ return "ifissp"; }
  static std::string description(){
    return "The ifissp parameter specifies the subsection of the fission\n"
           "spectrum covariance matrix to process.  The default value is -1,\n"
           "which means process the subsection that includes efmean.  The\n"
           "value for ifissp that appears in njoy's standard output will\n"
           "equal the subsection containing efmean.  This parameter is only\n"
           "used if mfcov = 35.";
  }
  static Value_t defaultValue( const int ){ return -1; }
  static bool verify( const Value_t ifissp, const int mfcov ){
    return ( mfcov != 35 or ( ifissp == -1 or ifissp > 0 ) );
  }
};
