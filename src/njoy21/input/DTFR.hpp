class DTFR {
public:
  #include "njoy21/input/DTFR/Card1.hpp"
  #include "njoy21/input/DTFR/Card2.hpp"
  #include "njoy21/input/DTFR/Card3.hpp"
  #include "njoy21/input/DTFR/Card3a.hpp"
  #include "njoy21/input/DTFR/Card4.hpp"
  #include "njoy21/input/DTFR/Card5.hpp"
  #include "njoy21/input/DTFR/Card6.hpp"
  #include "njoy21/input/DTFR/Card7.hpp"
  #include "njoy21/input/DTFR/Card8.hpp"

  using Card5List = std::vector< Card5 >;

  using ControlTuple = std::tuple< Card3, 
                           optional< Card3a >, Card4, Card5List >;
  using ControlVariant = std::variant< ControlTuple, Card6 >;
  
  using Card8List = std::vector< Card8 >;

  Card1 card1;
  Card2 card2;
  ControlVariant controlVariant;
  Card7 card7;
  Card8List card8List; 
  static ControlVariant 
  buildControlVariant(iRecordStream<char>& is, Card2& card2 ) {
        // Either do cards 3-5...
        if ( card2.iedit.value == 0 ){
          auto card3 = Card3( is );
	
	  auto card3a = 
            (card3.ntherm.value != 0 ) ? 
	      optional<Card3a>(Card3a( is )) : std::nullopt;

	  auto card4 = Card4( is, card3.iptotl);
          
	  Card5List card5List;

	  // Get all the card5 values. The # of card5 cards
	  // is specified by ned
	  try {
            for ( int n = 0; n < card3.ned.value; n++ ){
              card5List.emplace_back( is );
	    }
	  }
          catch( std::exception& e ){
            Log::info( "Failed reading card5" );
	    Log::info( "Expecting {} cards but instead got {} card(s)",
              card3.ned.value, card5List.size() );
	    throw e;
	  }
	 ControlTuple t(card3, card3a, card4, card5List ); 
	 return t;
	}
	// ...or do cards 6-8
        else {
          auto card6 = Card6( is );
	  return card6; 
	}   
  }

  template< typename Char >
  DTFR( iRecordStream<Char>& is )
    try :
      card1( is  ), 
      card2( is  ),
      controlVariant( buildControlVariant( is, this->card2 ) ),
      card7( is )
      {  
        do {
          card8List.emplace_back( is );
        }
        while ( card8List.back().hisnam.value );
        card8List.pop_back();
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating DTFR input");
      throw e;
    }
    
};
