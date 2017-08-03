
static optional<PairCorrelTuple> 
buildPairCorrelTuple( iRecordStream<char>& is ){

  auto card17 = Card17( is );
  auto card18 = Card18( is, card17.nka );
  return PairCorrelTuple( card17, card18 );

}
