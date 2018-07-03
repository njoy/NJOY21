struct Mtname {
  using Value_t = std::string;
  static std::string name(){ return "mtname"; }

  static std::string description(){
    return 
        "The mtname argument is a textual description of the ENDF Section to\n"
        "be processed.\n"
        "\n"
        "The argument must be less than 16 characters long.";
  }

  static Value_t defaultValue( const int ){ return ""; }
  static bool verify( const Value_t M, const int mfd ){ 
    if( mfd == 0 ){
      return true;
    }
    else{
      return ( M.size() < 16 ) and ( M.size() > 0 );
    }
  }
};
