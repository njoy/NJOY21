
static optional<OscillatorTuple> 
buildOscillatorTuple( iRecordStream<char>& is, Card13& card13, Card14& card14 ){

  auto card15 = Card15( is, card14.nd );
  auto card16 = Card16( is, card14.nd, card13.twt, card13.tbeta );
  return OscillatorTuple( card15, card16 );

}
