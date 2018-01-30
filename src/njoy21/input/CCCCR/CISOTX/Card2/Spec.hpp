struct Spec {
  using Value_t = std::vector< double >;
  static std::string name(){ return "spec"; }
  static std::string description(){
    return "The spec parameter specifies the flux values used to collapse\n"
           "the groupr fission matrix into a chi vector.  ngroup values are\n"
           "expected.";
  }
  static bool verify( const Value_t spec, const int ){
    for( auto i : spec ){
      if( i < 0.0 ) return false;
    }
    return true;
  }
};
