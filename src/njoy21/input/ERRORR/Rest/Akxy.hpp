struct Akxy {
  using Value_t = std::vector< double >;
  static std::string name(){ return "akxy"; }
  static std::string description(){

  }
  static Value_t defaultValue( const int size, const size_t diag ){
    std::vector< double > retval( size, 0.0 );
    retval.at( diag ) = 1.0;
    return retval;
  }
  static bool verify( const Value_t akxy, const size_t ){
    for( auto i : akxy ){
      if( i < -1.0 or i > 1.0 ) return false;
    }
    return true;
  }
};
