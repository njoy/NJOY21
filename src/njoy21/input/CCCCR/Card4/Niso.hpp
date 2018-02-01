struct Niso{
  using Value_t = int;
  static std::string name(){ return "niso"; }
  static std::string description(){
    return "The niso parameter specifies the desired number of isotopes.";
  }
  static bool verify( const Value_t niso ){
    return ( niso > 0 and niso <= 200 );
  }
};
