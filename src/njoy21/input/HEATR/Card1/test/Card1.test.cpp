#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating HEATR Card1 inputs",
  "[HEATR], [Card1]"){
  GIVEN( "valid HEATR Card1 inputs" ){
    WHEN( "all inputs are provided" ){
      iRecordStream<char> iss1( std::istringstream("20 21 22 23\n") );
      iRecordStream<char> iss2( std::istringstream("-20 21 22 -23\n") );
      iRecordStream<char> iss3( std::istringstream("20 -21 -22 23\n") );
      THEN( "the returned values are correct" ){
        {
          HEATR::Card1 card1( iss1 );
          REQUIRE( card1.nendf.value == 20 );
          REQUIRE( card1.nin.value == 21 );
          REQUIRE( card1.nout.value == 22 );
          REQUIRE( card1.nplot.value == 23 );
        } 
        {
          HEATR::Card1 card1( iss2 );
          REQUIRE( card1.nendf.value == -20 );
          REQUIRE( card1.nin.value == 21 );
          REQUIRE( card1.nout.value == 22 );
          REQUIRE( card1.nplot.value == -23 );
        }
        {
          HEATR::Card1 card1( iss3 );
          REQUIRE( card1.nendf.value == 20 );
          REQUIRE( card1.nin.value == -21 );
          REQUIRE( card1.nout.value == -22 );
          REQUIRE( card1.nplot.value == 23 );
        }
      } // THEN
    } // WHEN
    WHEN( "optional input not provided" ){
      iRecordStream<char> iss1( std::istringstream("20 21 22 /\n") );
      iRecordStream<char> iss2( std::istringstream("-20 -21 -22 /\n") );
      THEN( "the returned values are correct" ){
        {
          HEATR::Card1 card1( iss1 );
          REQUIRE( card1.nendf.value == 20 );
          REQUIRE( card1.nin.value == 21 );
          REQUIRE( card1.nout.value == 22 );
          REQUIRE( card1.nplot.value == 0 );
        } 
        {
          HEATR::Card1 card1( iss2 );
          REQUIRE( card1.nendf.value == -20 );
          REQUIRE( card1.nin.value == -21 );
          REQUIRE( card1.nout.value == -22 );
          REQUIRE( card1.nplot.value == 0 );
        }
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid HEATR Card1 inputs" ){
    WHEN( "all inputs are provided" ){
      iRecordStream<char> iss1( std::istringstream("19 21 22 23\n") );
      iRecordStream<char> iss2( std::istringstream("-20 -21 22 -23\n") );
      iRecordStream<char> iss3( std::istringstream("20 -21 -22 21\n") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card1( iss1 ) );
        REQUIRE_THROWS( HEATR::Card1( iss2 ) );
        REQUIRE_THROWS( HEATR::Card1( iss3 ) );
      } // THEN
    } // WHEN
    WHEN( "optional input not provided" ){
      iRecordStream<char> iss1( std::istringstream("19 21 22 /\n") );
      iRecordStream<char> iss2( std::istringstream("-20 -21 22 /\n") );
      iRecordStream<char> iss3( std::istringstream("20 -21 -21 /\n") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card1( iss1 ) );
        REQUIRE_THROWS( HEATR::Card1( iss2 ) );
        REQUIRE_THROWS( HEATR::Card1( iss3 ) );
      } // THEN
    } // WHEN
  } //GIVEN
} // SCENARIO

