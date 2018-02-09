#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
  "[DFTR], [Card1]" ){
  GIVEN( "valid COVR card1 inputs" ){
    WHEN( "all COVR card1 inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "-21 23 24" ) );
      COVR::Card1 card1( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( -21 == card1.nin.value );
        REQUIRE( 23  == card1.nout.value );
        REQUIRE( 24  == card1.nplot.value );
      } // THEN
    } // WHEN
    WHEN( "optional parameter nplot not provided" ){
      iRecordStream<char> iss( std::istringstream( "21 22 / ") );
      COVR::Card1 card1( iss );
      THEN( "default values for npend and nplot used" ){
        REQUIRE( 21 == card1.nin.value );
        REQUIRE( 22 == card1.nout.value );
        REQUIRE( 0  == card1.nplot.value );
      } // THEN
    } // WHEN
    WHEN( "no nout file desired" ){
      iRecordStream<char> iss( std::istringstream( "21 0 23" ) );
      COVR::Card1 card1( iss );
      THEN( "entries correspond to correct values" ){
        REQUIRE( 21 == card1.nin.value );
        REQUIRE( 0  == card1.nout.value);
        REQUIRE( 23 == card1.nplot.value);
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid COVR card1 inputs" ){
   WHEN( "neither output format chosen" ){
      iRecordStream<char> iss1( std::istringstream( "21 0 0" ) );
      iRecordStream<char> iss2( std::istringstream( "21 0 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card1( iss1 ) );
        REQUIRE_THROWS( COVR::Card1( iss2 ) );
      } // THEN
    } // WHEN    
   WHEN( "input value repeated" ){
      iRecordStream<char> iss( std::istringstream( "21 23 23" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card1( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
