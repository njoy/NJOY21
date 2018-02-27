struct Mat1 {
  using Value_t = int;
  static std::string name(){ return "mat1"; }
  static std::string description(){
    return "The mat1 parameter specifies the material for the cross-material\n"
           "reaction to be added to the covariance reaction list.  A material\n"
           "value of zero exits the loop.";
  }
  static bool verify( const Value_t mat1 ){
    return ( argument::common::Matd::verify( mat1 ) or mat1 == 0 );
  }
};
