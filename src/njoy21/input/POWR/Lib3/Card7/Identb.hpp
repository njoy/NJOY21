struct Identb{
  using Value_t = std::vector< int >;
  static std::string name(){ return "identb"; }
  static std::string description(){
    return "The identb parameter specifies the ident of each fissionable\n"
           "burnup isotope.";
  }
  static bool verify( const Value_t identb, const int ){
    for( auto ident : identb ){
      if( ident < -100 ) return false;
    }
    return true;
  }
};
