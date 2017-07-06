#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card3 inputs",
  "[DFTR], [Card3]" ){
  GIVEN( "valid DTFR card3 inputs" ){
    WHEN( "all DTFR card3 inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "5 12 4 5 16 1 0" ) );
      DTFR::Card3 card3( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( 5  == card3.nlmax.value );
        REQUIRE( 12 == card3.ng.value );
        REQUIRE( 4  == card3.iptotl.value );
        REQUIRE( 5  == card3.ipingp.value );
        REQUIRE( 16 == card3.itabl.value );
        REQUIRE( 1  == card3.ned.value );
        REQUIRE( 0  == card3.ntherm.value );
      } // THEN
    } // WHEN
    WHEN( "Ned and Ntherm not provided" ){
      iRecordStream<char> iss( std::istringstream( "5 12 4 5 16 / ") );
      DTFR::Card3 card3( iss );
      THEN( "default values for ned and ntherm used" ){
        REQUIRE(  5  == card3.nlmax.value );
        REQUIRE( 12 == card3.ng.value );
        REQUIRE( 4  == card3.iptotl.value );
        REQUIRE( 5  == card3.ipingp.value );
        REQUIRE( 16 == card3.itabl.value );
        REQUIRE( 0  == card3.ned.value );
        REQUIRE( 0  == card3.ntherm.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid DTFR card3 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss1( std::istringstream( "-1 12 -5 5 25 1 0" ) );
      iRecordStream<char> iss2( std::istringstream( "5 12 4 5 15 1 0" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card3( iss1 ) );
        REQUIRE_THROWS( DTFR::Card3( iss2 ) );
      } // THEN
    } // WHEN
    WHEN( "not all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "0 0 0 0 1 / ") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card3( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
