struct Ngen3{
  using Value_t = int;
  static std::string name(){ return "ngen3"; }
  static std::string description(){
    return "The ngen3 parameter indicates the file number on which the\n"
           "incident proton data, produced by GROUPR, can be found.\n"
           "The allowable values have absolute values between 20 and 99,\n"
           "inclusively.  If the value is negative, it means that the file\n"
           "is in binary format.  If it is positive, the file is in\n"
           "plaintext.\n\n"
           "The default value is 0, meaning no data is provided.";
  }
  static Value_t defaultValue( const Value_t, const Value_t, const Value_t )
  {
    return 0;
  }
  static bool verify( const Value_t ngen3,
                      const Value_t nmatx,
                      const Value_t ngen2,
                      const Value_t ngen1 ){
    return ngen3 == 0 or
           ( argument::common::Nin::verify( ngen3 ) and
             std::abs( ngen3 ) != std::abs( nmatx ) and
             std::abs( ngen3 ) != std::abs( ngen2 ) and
             std::abs( ngen3 ) != std::abs( ngen1 ) );
  }
};
