struct Nbrks{
  using Value_t = int;
  static std::string name(){ return "nbrks"; }
  static std::string description(){
    return "The nbrks parameter specifies the output unit for brkoxs.  If\n"
           "set to 0, no brkoxs input will be read.";
  }
  static Value_t defaultValue( const Value_t, const Value_t ){ return 0; }
  static bool verify( const Value_t nbrks, const Value_t nisot,
                      const Value_t nin ){
    return ( nbrks == 0 or ( nbrks > -100 and nbrks < -19
             and nbrks != nisot and std::abs( nbrks ) != nin ) );
  }
};
