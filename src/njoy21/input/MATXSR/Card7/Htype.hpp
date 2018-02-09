struct Htype{
  using Value_t = std::vector< std::string >;

  static std::string name(){ return "htype"; }
  static std::string description(){
    return "The htype parameter specifies the hollerith identifier for data\n"
           "types.";
  }
  static bool verify( const Value_t htypeList, const unsigned int ntype ){
    if( htypeList.size() != ntype ) return false;
    for( std::string htype : htypeList ){
      if( htype.size() > 8 ){
        Log::info( "htype argument: {} is longer than 8 characters.\n", htype );
        return false;
      }
    }
    return true;
  }
};
