struct Legord {
  using Value_t = int;
  static std::string name(){ return "legord"; }
  static std::string description(){
    return "The legord parameter specifies the legendre order for calculating\n"
           "the covariances.  This is only used if mfcov = 34.  The default\n"
           "value is 1.\n\n"
           "At this time, this value is hardcoded to only allow legord = 1.";
  }
  static Value_t defaultValue( const int ){ return 1; }
  static bool verify( const Value_t legord, const int mfcov ){
    return ( mfcov != 34 or legord == 1 );
  }
};
