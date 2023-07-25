#define PAIR( routine ) \
  std::make_pair< std::string, parser >                              \
  ( #routine,                                                        \
    []( lipservice::iRecordStream< char >& inputStream ) \
      -> std::unique_ptr< interface::Routine > \
    { return std::make_unique< routine >( inputStream ); } )

std::unique_ptr< interface::Routine >
parse( std::string& label, lipservice::iRecordStream< char >& input ){
  static const std::unordered_map< std::string, parser > parserMap =
    { PAIR( MODER ),  PAIR( RECONR ), PAIR( BROADR ), PAIR( PURR ),
      PAIR( UNRESR ), PAIR( ACER ),   PAIR( GASPR ),  PAIR( HEATR ),
      PAIR( GROUPR ), PAIR( VIEWR ),  PAIR( MIXR ),   PAIR( DTFR ),
      PAIR( THERMR ), PAIR( LEAPR ),  PAIR( RESXSR ), PAIR( MATXSR ),
      PAIR( GAMINR ), PAIR( PLOTR ),  PAIR( COVR ),   PAIR( WIMSR ),
      PAIR( POWR ),   PAIR( CCCCR ),  PAIR( ERRORR ) };
  return parserMap.at( label )( input );
}
#undef PAIR
