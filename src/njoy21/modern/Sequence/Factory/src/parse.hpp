#define PAIR( routine ) \
std::make_pair< std::string, parser >                              \
( #routine,                                                        \
  []( lipservice::iRecordStream< char >& inputStream )             \
    -> std::unique_ptr< interface::Routine >                       \
  { return std::make_unique< routine >( inputStream ); } )

std::unique_ptr< interface::Routine >
parse( std::string& label, lipservice::iRecordStream< char >& input ){
  static const std::unordered_map< std::string, parser > parserMap =
    { PAIR( LEAPR ) };
      
  return parserMap.at( label )( input );
}
#undef PAIR
