
using Card5aList = std::vector<Card5a>;
using ControlTuple = std::tuple< Card4, Card5, Card5aList >;

static optional<ControlTuple> buildControlTuple( 
  iRecordStream<char>& is, Card2& card2 ){
  if( card2.nqa.value > 0 ){
    auto card4 = Card4( is, card2.nqa );
    auto card5 = Card5( is, card2.nqa );
    Card5aList card5aList;
    for( const auto& qa : card5.qa.value ){
      if( qa >= 99e6 * dimwits::electronVolts ){
        card5aList.emplace_back( is );
      }
    }
    return ControlTuple( std::move(card4), std::move(card5), 
      std::move(card5aList) );
  }
  
  return std::nullopt;
}

