struct Mfcov {
  using Value_t = int;
  static std::string name(){ return "mfcov"; }
  static std::string description(){
    return "The mfcov parameter specifies the endf covariance file to be\n"
           "processed.  Accepted values are 31, 33, 34, 35, 40, 32, -33, and\n"
           "333.  The default value is 33.\n\n"
           "Note: contribution to group cross section covariances from\n"
           "      resonance-parameter uncertainties (mf=32) is included when\n"
           "      mfcov=33 is specified.\n"
           "mf=-33 -- high speed calc for test case\n"
           "mf=333 -- hight speed calc for test case (faster)";
  }
  static Value_t defaultValue( const int ){ return 33; }
  static bool verify( const Value_t mfcov, const int ngout ){
    if( ( mfcov == 31 or mfcov == 35 or mfcov == 40 ) and ngout == 0 ){
      Log::error( "Ngout cannot equal zero if mfcov is 31, 35, or 40." );
      throw std::exception();
    }
    return ( mfcov == 31 or std::abs( mfcov ) == 33 or mfcov == 34 or
             mfcov == 35 or mfcov == 40 or mfcov == 333 );
  }
};
