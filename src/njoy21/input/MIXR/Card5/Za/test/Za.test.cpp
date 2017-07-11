#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Za input values", 
  "[MIXR],[Card5],[Za]"){
  GIVEN( "valid za value" ){
    std::vector<int> validValues{1, 26000, 199999, 200000};
    THEN( "the returned class has the correct value" ){
      for( auto& za : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( za ) ) );
	REQUIRE( za == argument::extract< MIXR::Card5::Za >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid za value" ){
    std::vector<int> invalidValues{-1, 0, 200001, 200002};
    THEN( "an exception is thrown" ){
      for( auto& za : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( za ) ) );
        REQUIRE_THROWS( argument::extract< MIXR::Card5::Za >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
