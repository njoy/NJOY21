struct Mtname {
  using Value_t = std::string;
  static std::string name(){ return "mtname"; }

  static std::string description(){
    return 
        "The mtname argument is a textual description of the ENDF Section to\n"
        "be processed.";//\n"
//        "\n"
//        "The argument must be less than 16 characters long.";
  }

  static Value_t defaultValue( const Argument< Mfd >& ){ return ""; }
  static bool verify( const Value_t , const Argument< Mfd >& mfd ){ 
    if( mfd.value == 0 ){
      return true;
    }
    else{
//      Commented because, while the fortran seems to suggest that the max
//      accepted characters is 15, the NJOY2016 output is able to reproduce
//      longer strings and test problem 1 uses longer strings.
//
//      return ( M.size() < 16 ) and ( M.size() > 0 );
      return true;
    }
  }
};
