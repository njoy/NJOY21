struct Iread {
  using Value_t = int;
  static std::string name(){ return "iread"; }
  static std::string description(){
    return "The iread parameter specifies the method of mt and ek\n"
           "generation.\n\n"
           "value      meaning\n"
           "-----      -------\n"
           "  0        program calculated mts     ( default )\n"
           "  1        input mts and eks\n"
           "  2        calculated mts plus extra mat1-mt1 pairs from input";
  }
  static Value_t defaultValue(const int ){ return 0; }
  static bool verify( const Value_t iread, const int ngout ){
    if( iread == 2 and ngout == 0 ){
      Log::error( "Ngout may not have a value of zero when iread has a value"
                  "of 2." );
      throw std::exception();
    }
    return ( iread == 0 or iread == 1 or iread == 2 );
  }
};
