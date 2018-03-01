struct Nstan {
  using Value_t = int;
  static std::string name(){ return "nstan"; }
  static std::string description(){
    return "The nstan parameter specifies the unit for ratio-to-standard\n"
           "tape.  The default value is zero.";
  }
  static Value_t defaultValue( const int, const int, const int, const int,
                               const int ){
    return 0;
  }
  static bool verify( const int nstan, const int nendf, const int npend,
                      const int ngout, const int nout, const int nin ){
    return ( nstan == 0 or ( argument::common::Nin::verify( nstan ) and
                             std::abs( nstan ) != std::abs( nendf ) and
                             std::abs( nstan ) != std::abs( npend ) and
                             std::abs( nstan ) != std::abs( ngout ) and
                             std::abs( nstan ) != std::abs( nout ) and
                             std::abs( nstan ) != std::abs( nin ) ) );
  }
};
