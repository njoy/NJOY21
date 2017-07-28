#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card1 input values",
  "[LEAPR], [Card1]" ){
  GIVEN( "valid card1 entry" ){
    std::vector<int> validValues{-20, 20, 42, 99, -99};
    THEN( "the returned values are correct" ){
      for( auto nout : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nout ) ) );
        LEAPR::Card1 card1( iss );
        REQUIRE( card1.nout.value == nout );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid card1 values" ){
    std::vector<int> invalidValues{-19, 19, -1, 1, 100, -100};
    THEN( "an exception is thrown" ){
      for( auto nout : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nout ) ) );
        REQUIRE_THROWS( LEAPR::Card1( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

