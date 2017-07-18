class HEATR {
public:
  #include "njoy21/input/HEATR/Card1.hpp"
  #include "njoy21/input/HEATR/Card2.hpp"
  #include "njoy21/input/HEATR/Card3.hpp"
  #include "njoy21/input/HEATR/Card4.hpp"
  #include "njoy21/input/HEATR/Card5.hpp"
  #include "njoy21/input/HEATR/Card5a.hpp"

  using Card5aList = std::vector<Card5a>;
  using ControlTuple = std::tuple< Card4, Card5, Card5aList >;

  Card1 card1;
  Card2 card2;
  optional<Card3> card3;
  optional<ControlTuple> controlTuple;

  static optional<Card3> buildCard3( iRecordStream<char>& is, Card2& card2 ){
    if( card2.npk.value > 0 ){
      return Card3( is, card2.npk );
    }
    return std::nullopt;
  } 
  
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
      ControlTuple ct( card4, card5, card5aList );
      return ct;
    }
    
    return std::nullopt;
  }

  template< typename Char >
  HEATR( iRecordStream<Char>& is )
    try:
      card1( is ),
      card2( is, this->card1.nplot ),
      card3( buildCard3( is, this->card2 ) ),
      controlTuple( buildControlTuple( is, this->card2 ) ){
      }
     catch( std::exception& e ){
       Log::info( "Trouble while validating HEATR input" );
       throw e;
     } 
};
