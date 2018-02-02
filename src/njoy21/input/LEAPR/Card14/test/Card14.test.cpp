#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card14 input values",
  "[LEAPR], [Card14]" ){
  GIVEN( "valid card14 entry" ){
    std::vector<int> validValues{0, 1, 2, 20};
    THEN( "the returned values are correct" ){
      for( auto& nd : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nd ) ) );
        LEAPR::Card14 card14( iss );
        REQUIRE( card14.nd.value == nd );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid card14 values" ){
    std::vector<int> invalidValues{-1, -100};
    THEN( "an exception is thrown" ){
      for( auto& nd : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nd ) ) );
        REQUIRE_THROWS( LEAPR::Card14( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

