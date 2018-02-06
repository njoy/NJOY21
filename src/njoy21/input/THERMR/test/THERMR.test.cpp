#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR input", 
  "[THERMR]" ){
  GIVEN( "valid THERMR cards" ){
    WHEN( "all entries are provided" ){
      iRecordStream<char> iss( std::istringstream( 
        "0 -22 -24\n"
        "0 1306 8 2 1 0 0 1 221 2\n"
        "350.0 450.0\n"
        "0.05 1.2/\n"
        ) );
      THERMR thermr( iss );
      THEN( "all cards should have the correct values" ){
        REQUIRE( thermr.card1.nendf.value == 0 );
        REQUIRE( thermr.card1.nin.value   == -22 );
        REQUIRE( thermr.card1.nout.value  == -24 );

        REQUIRE( thermr.card2.matde.value  == 0 );
        REQUIRE( thermr.card2.matdp.value  == 1306 );
        REQUIRE( thermr.card2.nbin.value   == 8 );
        REQUIRE( thermr.card2.ntemp.value  == 2 );
        REQUIRE( thermr.card2.iin.value    == 1 );
        REQUIRE( thermr.card2.icoh.value   == 0 );
        REQUIRE( thermr.card2.iform.value  == 0 );
        REQUIRE( thermr.card2.natom.value  == 1 );
        REQUIRE( thermr.card2.mtref.value  == 221 );
        REQUIRE( thermr.card2.iprint.value == 2 );
	
        REQUIRE( thermr.card3.tempr.value[0] == 350.0 * dimwits::kelvin );
        REQUIRE( thermr.card3.tempr.value[1] == 450.0 * dimwits::kelvin );

        REQUIRE( thermr.card4.tol.value  == 0.05 );
        REQUIRE( thermr.card4.emax.value == 1.2 * dimwits::electronVolts );
      } // THEN
    } // WHEN
    WHEN( "optional parameter not provided" ){
      iRecordStream<char> iss( std::istringstream( 
        "0 -22 -24\n"
        "0 1306 8 2 1 0 0 1 221 /\n"
        "350.0 450.0\n"
        "0.05 1.2/\n"
        ) );
      THERMR thermr( iss );
      THEN( "optional parameter should have the correct value" ){
        REQUIRE( thermr.card2.iprint.value == 0 );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid THERMR input" ){
    WHEN( "inconsistency between ntemp and tempr" ){
      iRecordStream<char> iss( std::istringstream( 
        "0 -22 -24\n"
        "0 1306 8 2 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN
    WHEN( "inconsistency between nendf and matde" ){
      iRecordStream<char> iss1( std::istringstream( 
        "0 -22 -24\n"
        "1 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );
      iRecordStream<char> iss2( std::istringstream( 
        "0 -22 -24\n"
        "1 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR( iss1) );
        REQUIRE_THROWS( THERMR( iss2 ) );
      } // THEN
    } // WHEN
    WHEN( "inconsistency between nendf and iin" ){
      iRecordStream<char> iss( std::istringstream(
        "0 -22 -24\n"
	"0 1306 8 1 2 0 0 1 221 2\n"
	"350.0\n"
	"0.05 1.2/\n"
      ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN
    WHEN( "card1 input files repeated" ){
      iRecordStream<char> iss( std::istringstream( 
        "20 20 21\n"
        "0 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN 
    WHEN( "invalid (out of range) card4 entry" ){
      iRecordStream<char> iss( std::istringstream( 
        "20 20 21\n"
        "0 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "1.e-6 1.2/\n"
        ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
