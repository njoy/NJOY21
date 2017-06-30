#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
  "[DFTR], [Card1]" ){
  GIVEN( "valid DTFR card1 inputs" ){
    WHEN( "all DTFR card1 inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "21 23 24 25" ) );
      DTFR::Card1 card1( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( 21 == card1.nin.value );
        REQUIRE( 23 == card1.nout.value );
        REQUIRE( 24 == card1.npend.value );
        REQUIRE( 25 == card1.nplot.value );
      } // THEN
    } // WHEN
    WHEN( "Optional parameters not provided" ){
      iRecordStream<char> iss( std::istringstream( "21 / ") );
      DTFR::Card1 card1( iss );
      THEN( "default values for ned and ntherm used" ){
        REQUIRE( 21 == card1.nin.value );
        REQUIRE( 0  == card1.nout.value );
        REQUIRE( 0  == card1.npend.value );
        REQUIRE( 0  == card1.nplot.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid DTFR card1 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "21 23 23 24" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card1( iss ) );
      } // THEN
    } // WHEN
    WHEN( "not all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "21 19 / ") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card1( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
