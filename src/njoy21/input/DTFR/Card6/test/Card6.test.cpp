#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card6 inputs",
  "[DFTR], [Card6]" ){
  GIVEN( "valid DTFR card6 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "8 12" ) );
      DTFR::Card6 card6( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( 8  == card6.nlmax.value );
        REQUIRE( 12 == card6.ng.value );
      } // THEN
    } // WHEN
    WHEN( "Nlmax and Ng not provided" ){
      iRecordStream<char> iss( std::istringstream( " / ") );
      DTFR::Card6 card6( iss );
      THEN( "default values for nlmax and ng used" ){
        REQUIRE(  5 == card6.nlmax.value );
        REQUIRE( 30 == card6.ng.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid DTFR card6 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "-1 3" ) );
      THEN( "an exception is raised" ){
        REQUIRE_THROWS( DTFR::Card6( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
