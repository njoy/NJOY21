struct Mts {
  using Value_t = std::vector< int >;
  static std::string name(){ return "mts"; }
  static std::string description(){
    return "The mts parameter specifies the nmt material values. The values\n"
           "should be valid mt values, in ascending order with no duplicates.";
  }
  static bool verify( const Value_t mts, const int ){
    if( mts.size() == 0 ){
      Log::error( "No materials were provided." );
      return false;
    }
    std::vector< int > used;
    for( auto i : mts ){
// Check for duplicates
      if( std::find( used.begin(), used.end(), i ) != used.end() ){
        Log::error( "Material value {} used more than once.", i );
        return false;
      }
// Check for valid values
      if( !argument::common::Matd::verify( i ) ){
        Log::info( "Material {} has an invalid value.", i );
        return false;
      }
      used.push_back( i );
    }
// Check for ascending order.
    auto unsortedStart = std::is_sorted_until( mts.begin(), mts.end() );
    if( unsortedStart != mts.end() ){
      Log::error( "Material not in ascending order.  {} > {}.",
                                            unsortedStart[-1], *unsortedStart );
      return false;
    }
    return true;
  }
};
