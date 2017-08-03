
static optional<TempSpecificTuple>
buildTempSpecificTuple( iRecordStream<char>& is, Card5& card5 ){
  auto card11 = Card11( is );
  auto card12 = Card12( is, card11.ni );
  auto card13 = Card13( is );
  auto card14 = Card14( is );

  // Cards 15 and 16
  auto oscillatorTuple = (card14.nd.value != 0 ) ? 
    buildOscillatorTuple( is, card13, card14 ) : std::nullopt;

  // Cards 17, and 18
  auto pairCorrelTuple = (card5.nsk.value != 0 ) ? 
    buildPairCorrelTuple( is ) : std::nullopt;
  
  return TempSpecificTuple( card11, card12, card13, card14,
    oscillatorTuple, pairCorrelTuple );
}  


