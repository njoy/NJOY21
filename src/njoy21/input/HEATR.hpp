class HEATR {
public:
  #include "njoy21/input/HEATR/Card1.hpp"
  #include "njoy21/input/HEATR/Card2.hpp"
  #include "njoy21/input/HEATR/Card3.hpp"
  #include "njoy21/input/HEATR/Card4.hpp"
  #include "njoy21/input/HEATR/Card5.hpp"
  #include "njoy21/input/HEATR/Card5a.hpp"

  using Card5aList = std::vector<Card5a>;
  using ControlTuple = std::tuple< Card4, Card5, optional< Card5aList > >;

  Card1 card1;
  Card2 card2;
  optional<Card3> card3;
  optional<ControlTuple> controlTuple;

  template< typename Char >
  HEATR( iRecordStream<Char>& is )
    try:
      card1( is ),
      card2( is, card1.nplot ){

        if( card2.npk.value > 0 ){
          this->card3 = Card3( is, card2.npk );
	}
        if( card2.nqa.value > 0 ){
          auto card4 = Card4( is, card2.nqa );
	  auto card5 = Card5( is, card2.nqa );
	  Card5aList card5aList;
	  for( const auto& qa : card5.qa.value ){
	    if( qa >= 99e6 * dimwits::electronVolts ){
	      card5aList.emplace_back( is );
	    }
	  }
	  auto card5a = ( card5aList.size() > 0 ) ?
            optional<Card5aList>(card5aList) : std::nullopt;
          controlTuple = ControlTuple( card4, card5, card5a ); 
	}

      }
     catch( std::exception& e ){
       Log::info( "Trouble while validating HEATR input" );
       throw e;
     } 



};
