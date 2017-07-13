#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card3a inputs",
  "[DFTR], [Card3a]" ){
  GIVEN( "valid DTFR card3a inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "221 125 4" ) );
      DTFR::Card3a card3a( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( 221 == card3a.mti.value );
        REQUIRE( 125 == card3a.mtc.value );
        REQUIRE( 4   == card3a.nlc.value );
      } // THEN
    } // WHEN
    WHEN( "Mtc and Nlc not provided" ){
      iRecordStream<char> iss( std::istringstream( "221 / ") );
      DTFR::Card3a card3a( iss );
      THEN( "default values for ned and ntherm used" ){
        REQUIRE( 221 == card3a.mti.value );
        REQUIRE( 0   == card3a.mtc.value );
        REQUIRE( 0   == card3a.nlc.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid DTFR card3a inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "1000 0 0" ) );
      THEN( "an exception is raised" ){
        REQUIRE_THROWS( DTFR::Card3a( iss ) );
      } // THEN
    } // WHEN
    WHEN( "default values are used" ){
      iRecordStream<char> iss( std::istringstream( "999 -1 /" ) );
      THEN( "an exception is raised" ){
        REQUIRE_THROWS( DTFR::Card3a( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
