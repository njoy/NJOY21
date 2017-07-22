
static optional<Card3> buildCard3( iRecordStream<char>& is, Card2& card2 ){
  if( card2.npk.value > 0 ){
    return Card3( is, card2.npk );
  }
  return std::nullopt;
}
