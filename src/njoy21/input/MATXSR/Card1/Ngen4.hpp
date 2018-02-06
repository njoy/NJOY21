struct Ngen4{
  using Value_t = int;
  static std::string name(){ return "ngen4"; }
  static std::string description(){
    return "The ngen4 parameter indicates the file number on which the\n"
           "incident deuteron data, produced by GROUPR, can be found.\n"
           "The allowable values have absolute values between 20 and 99,\n"
           "inclusively.  If the value is negative, it means that the file\n"
           "is in binary format.  If it is positive, the file is in\n"
           "plaintext. A value of 0 is also allowed.\n\n"
           "The default value is 0, meaning no data is provided.";
  }
  static Value_t defaultValue( const Value_t, const Value_t,
                               const Value_t, const Value_t )
  {
    return 0;
  }
  static bool verify( const Value_t ngen4,
                      const Value_t ngen3,
                      const Value_t nmatx,
                      const Value_t ngen2,
                      const Value_t ngen1 ){
    return MATXSR::Card1::Ngen3::verify( ngen4, nmatx, ngen2, ngen1 ) and
             std::abs( ngen4 ) != std::abs( ngen3 );
  }
};
