struct Hpart{
  using Value_t = std::vector< std::string >;
  static std::string name(){ return "hpart"; }
  static std::string description(){
    return "The hpart parameter specifies the hollerith identifier for\n"
           "particles.";
  }
  static bool verify( const Value_t hpartList, const unsigned int npart ){
    if( hpartList.size() != npart ) return false;
    for( auto hpart : hpartList ){
      if( hpart.size() > 10 or ( hpart.find( "'" ) != 0 and
                                 hpart.rfind( "'" ) != hpart.size() - 1 ) ){
        Log::info( "hpart argument : {} is longer than 8 characters\n", hpart );
        Log::info( "or the string is not delimited by quotes." );
        return false;
      }
    }

    return true;
  }
};
