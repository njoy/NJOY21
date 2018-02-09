struct Irelco {
  using Value_t = int;
  static std::string name(){ return "irelco"; }
  static std::string description(){
    return "The irelco parameter specifies the covariance form.\n\n"
           " 0 -- absolute covariance\n"
           " 1 -- relative covariance  ( default )";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t irelco ){
    return ( irelco == 0 or irelco == 1 );
  }
};
