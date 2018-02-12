struct Mt {
  using Value_t = int;
  static std::string name(){ return "mt"; }
  static std::string description(){
    return "The mt parameter specifies the material to be placed on the fake\n"
           "mt33 file that is being produced.  Accepted values are between\n"
           "0 and 9999, inclusively.  Zero is not an accepted material\n"
           "number, but it is used to signify the end of the material list.";
  }
  static bool verify( const Value_t mt ){
    return ( mt == 0 or argument::common::Matd::verify( mt ) );
  }
};
