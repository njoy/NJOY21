struct Nout {
  using Value_t = int;
  static std::string name(){ return "nout"; }
  static std::string description(){
    return "The nout parameter specifies the unit for the output\n"
           "covariance tape.  The default value is zero.";
  }
  static Value_t defaultValue( const int, const int, const int ){
    return 0;
  }
  static bool verify( const int nout, const int nendf, const int npend,
                      const int ngout ){
    return ( nout == 0 or ( argument::common::Nin::verify( nout ) and
                            std::abs( nout ) != std::abs( nendf ) and
                            std::abs( nout ) != std::abs( npend ) and
                            std::abs( nout ) != std::abs( ngout ) ) );
  }
};
