
template< typename Char >
static auto readCard5List( iRecordStream<Char>& is, const Card2& card2 ){
  std::vector<Card5> list;
  int previousMat = card2.mat1.value;
  while(true) {
    list.emplace_back( is );

    if ( list.back().mat1.value == 0 ){
      list.pop_back();
      break;
    }

    if( list.back().mat1.value < previousMat ){
      Log::error( "BROADR materials must be entered in ascending order." );
      Log::info( "Previous MAT value: {}", previousMat );
      Log::info( "Encountered MAT value: {}", list.back().mat1.value );
      Log::info( "Line number: {}", is.lineNumber );
      throw std::exception();
    }
    previousMat = list.back().mat1.value;
  }
  return list;
}
