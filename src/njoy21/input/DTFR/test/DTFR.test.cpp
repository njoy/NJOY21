#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR input, [DTFR]" ){
  GIVEN( "a card2 iedit value of 0" ){
    WHEN( "all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 0\n"
        "5 12 4 5 16 1 0\n"
        "pheat\n"
        "1 621 1\n"
        "0/"
        ) );

      DTFR dtfr( iss );
      THEN( "Card1 and Card2 should have correct inputs" ){
        REQUIRE( dtfr.card1.nin.value   == 33 );
        REQUIRE( dtfr.card1.nout.value  == 35 );
        REQUIRE( dtfr.card1.npend.value == 31 );
        REQUIRE( dtfr.card1.nplot.value == 36 );

        REQUIRE( dtfr.card2.iprint.value ==  1 );
        REQUIRE( dtfr.card2.ifilm.value  ==  1 );
        REQUIRE( dtfr.card2.iedit.value  ==  0 );

      } // THEN
  
      THEN( "Card3 and Card4 should exist with correct inputs" ){
        REQUIRE( dtfr.card3 );
        REQUIRE( dtfr.card4 );
        REQUIRE( dtfr.card5List );
  
        REQUIRE( dtfr.card3->nlmax.value  == 5  );
        REQUIRE( dtfr.card3->ng.value     == 12 );
        REQUIRE( dtfr.card3->iptotl.value == 4  );
        REQUIRE( dtfr.card3->ipingp.value == 5  );
        REQUIRE( dtfr.card3->itabl.value  == 16 );
        REQUIRE( dtfr.card3->ned.value    == 1  );
        REQUIRE( dtfr.card3->ntherm.value == 0  );
      
        REQUIRE( dtfr.card4->hollerithNames.value[0] == "pheat" );

        REQUIRE( 1 == dtfr.card5List->size() );

        REQUIRE( 1   == dtfr.card5List->front().jpos.value );
        REQUIRE( 621 == dtfr.card5List->front().mt.value   );
        REQUIRE( 1   == dtfr.card5List->front().mult.value );

      } // THEN

      THEN( "Card6, Card7, and Card8 should not be extracted" ){
        REQUIRE( not dtfr.card6 );
        REQUIRE( not dtfr.card7 );
        REQUIRE( not dtfr.card8 );
      } // THEN
    } // WHEN

    WHEN( "not all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 0\n"
        "5 12 4 5 16 1 0\n"
        "pheatlong\n"
        "1 621 1\n"
        "0/"
        ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR ( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a card2 iedit value of 1" ){
    WHEN( "all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 1\n"
        "5 30\n"
        "0 0\n"
        "hisnam 125 1 300\n"
        "0/"
        ) );

      DTFR dtfr( iss );
      THEN( "Card1 and Card2 should have correct inputs" ){
        REQUIRE( dtfr.card1.nin.value   == 33 );
        REQUIRE( dtfr.card1.nout.value  == 35 );
        REQUIRE( dtfr.card1.npend.value == 31 );
        REQUIRE( dtfr.card1.nplot.value == 36 );

        REQUIRE( dtfr.card2.iprint.value ==  1 );
        REQUIRE( dtfr.card2.ifilm.value  ==  1 );
        REQUIRE( dtfr.card2.iedit.value  ==  1 );

      } // THEN

      THEN( "Card3 and Card4 do not exist" ){
        REQUIRE( not dtfr.card3 );
        REQUIRE( not dtfr.card4 );
      } // THEN

      THEN( "Card6, Card7, Card8 exist with correct values" ){ 
        REQUIRE( dtfr.card6 );
        REQUIRE( dtfr.card7 );
        REQUIRE( dtfr.card8 );

        REQUIRE( dtfr.card6->nlmax.value  == 5   );
        REQUIRE( dtfr.card6->ng.value     == 30  );
        REQUIRE( dtfr.card7->nptabl.value == 0   );
        REQUIRE( dtfr.card7->ngp.value    == 0   );
        REQUIRE( dtfr.card8->hisnam.value == "hisnam"  );
        REQUIRE( dtfr.card8->mat.value    == 125 );
        REQUIRE( dtfr.card8->jsigz.value  == 1   );
        REQUIRE( dtfr.card8->dtemp.value  == 300*dimwits::kelvin );
      } // THEN
    } // WHEN
    WHEN( "not all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 1\n"
        "5 30\n"
        "0 0\n"
        "hisnam 125 1 -300\n"
        "0/"
        ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR ( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
