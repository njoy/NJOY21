struct Akxy {
  using Value_t = std::vector< double >;
  static std::string name(){ return "akxy"; }
  static std::string description(){
    return "The akxy parameter specifies the derived cross section\n"
           "coefficients.  These values populate a 3-dimensional matrix,\n"
           "which is filled one line of nmt values at a time by this\n"
           "parameter.  The default value will generate an identity matrix\n"
           "for each energy group.";
  }
  static Value_t defaultValue( const int nmt, const int diag ){
    std::vector< double > retval( nmt, 0.0 );
    retval.at(diag) = 1.0;
    return retval;
  }
  static bool verify( const Value_t akxy, const int ){
    auto a = std::find_if( akxy.begin(), akxy.end(), [](double d){
                                            return ( std::abs( d ) > 1.0 ); } );

    if( a != akxy.end() ){
      Log::error( "Derived cross section coefficent ({}) out of bounds [-1,1].",
                  *a );
      return false;
    }

    return true;
  }
};
