struct Nin {
  using Value_t = int;
  static std::string name(){ return "nin"; }
  static std::string description(){
    return "The nin parameter specifies the unit for input covariance\n"
           "input tape.  the default value is zero.";
  }
  static Value_t defaultValue( const int, const int, const int, const int ){
    return 0;
  }
  static bool verify( const int nin, const int nendf, const int npend,
                      const int ngout, const int nout ){
    return ( nin == 0 or ( argument::common::Nin::verify( nin ) and
                           std::abs( nin ) != std::abs( nendf ) and
                           std::abs( nin ) != std::abs( npend ) and
                           std::abs( nin ) != std::abs( ngout ) and
                           std::abs( nin ) != std::abs( nout ) ) );
  }
};
