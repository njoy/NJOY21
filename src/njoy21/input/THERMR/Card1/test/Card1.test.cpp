#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR Card1 inputs",
  "[THERMR], [Card1] "){
  GIVEN( "valid Card1 inputs" ){
    WHEN( "thermal scattering data provided" ){
      iRecordStream<char> iss( std::istringstream("20 21 22") );
      THEN( "the extracted values are correct" ){
        THERMR::Card1 card1( iss );
        REQUIRE( card1.nendf.value == 20 );
        REQUIRE( card1.nin.value == 21 );
        REQUIRE( card1.nout.value == 22 );
      } // THEN
    } // WHEN
    WHEN( "thermal scattering data not provided" ){
      iRecordStream<char> iss( std::istringstream("0 21 22") );
      THEN( "the extracted values are correct" ){
        THERMR::Card1 card1( iss );
        REQUIRE( card1.nendf.value == 0 );
        REQUIRE( card1.nin.value == 21 );
        REQUIRE( card1.nout.value == 22 );
      } // THEN
    } // WHEN
  } // GIVEN
  
  GIVEN( "invalid Card1 inputs" ){
    WHEN( "an input tape is reused" ){    
      iRecordStream<char> iss1( std::istringstream("20 20 21\n") );
      iRecordStream<char> iss2( std::istringstream("20 21 20\n") );
      iRecordStream<char> iss3( std::istringstream("20 21 21\n") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card1( iss1 ) );
        REQUIRE_THROWS( THERMR::Card1( iss2 ) );
        REQUIRE_THROWS( THERMR::Card1( iss3 ) );
      } // THEN
    } // WHEN
    WHEN( "an input tape is out of range" ){
      iRecordStream<char> iss1( std::istringstream("20 21 100\n") );
      iRecordStream<char> iss2( std::istringstream("20 19 20\n") );
      iRecordStream<char> iss3( std::istringstream("19 20 22\n") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card1( iss1 ) );
        REQUIRE_THROWS( THERMR::Card1( iss2 ) );
        REQUIRE_THROWS( THERMR::Card1( iss3 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
