#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card6 b7 input values", 
  "[LEAPR], [Card6], [B7]"){
  GIVEN( "valid b7 input values" ){
    std::vector<int> validValues{0, 1, 2};
    THEN( "the returned class has the correct value" ){
      for( auto& b7 : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( b7 ) ) );
        REQUIRE( b7 == argument::extract< LEAPR::Card6::B7 >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid b7 values" ){
    std::vector<int> invalidValues{-1, 3};
    THEN( "an exception is thrown" ){
      for( auto& b7 : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( b7 ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card6::B7 >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
