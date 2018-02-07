struct Scat{
  using Value_t = std::vector< double >;
  static std::string name(){ return "scat"; }
  static std::string description(){
    return "The scat parameter specifies the 12-l1+1 scattering values for\n"
           "this energy group.";
  }
  static bool verify( const Value_t scatList, const int ){
    for( auto scat : scatList ){
      if( scat < 0.0 ) return false;
    }
    return true;
  }
};
