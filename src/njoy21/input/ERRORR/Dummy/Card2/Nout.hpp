struct {
  using Value_t = int;
  static std::string name(){ return "nout"; }
  static std::string description(){
    return "The nout parameter specifies the output tape.";
  }
  static bool verify( const Value_t nout, const int nin ){
    return ( argument::common::Nin::verify( nout ) and
             std::abs( nin ) != std::abs( nout ) );
  }
};
