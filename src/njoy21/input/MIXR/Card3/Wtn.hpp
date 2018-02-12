struct Wtn {
  using Value_t = double;
  static std::string name(){ return "wtn"; }
  static std::string description(){
    return "The wtn parameter specifies the weighting factor for the material\n"
           "specified by the matn parameter.  Allowable values range from 0.0\n"
           "to 1.0.";
  }
  static bool verify( const Value_t wtn ){
    return ( wtn > 0.0 and wtn <= 1.0 );
  }
};
