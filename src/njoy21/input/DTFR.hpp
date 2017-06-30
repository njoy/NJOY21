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

  Card1 card1;
  Card2 card2;
  optional< Card3  > card3;
  optional< Card3a > card3a;
  optional< Card4  > card4;
  optional< std::vector< Card5 > > card5List;
  optional< Card6  > card6;
  optional< Card7  > card7;
  optional< Card8  > card8;

  template< typename Char >
  DTFR( iRecordStream<Char>& is )
    try :
      card1( is  ), 
      card2( is  ){

        // Either do cards 3-5...
        if ( this->card2.iedit.value == 0 ){
          this->card3 = Card3( is );
	
	  if ( this->card3->ntherm.value != 0 ){
            this->card3a = Card3a( is );
	  }

	  this->card4 = Card4( is, this->card3->iptotl );

	  // Get all the card5 values. The # of card5 cards
	  // is specified by ned
	  try {
            card5List = std::vector< Card5 >();
            for ( int n = 0; n < card3->ned.value; n++ ){
              card5List->emplace_back( is );
	    }
	  }
          catch( std::exception& e ){
            Log::info( "Failed reading card5" );
	    Log::info( "Expecting {} cards but instead got {} card(s)",
              card3->ned.value, card5List->size() );
	    throw e;
	  }
	}
	// ...or do cards 6-8
        else {
          this->card6 = Card6( is );
          this->card7 = Card7( is );
          this->card8 = Card8( is );
	}
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating DTFR input");
      throw e;
    }
    
};
