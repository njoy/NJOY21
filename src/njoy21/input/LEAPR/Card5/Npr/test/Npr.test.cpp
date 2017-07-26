#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Npr input values", 
  "[LEAPR], [Card5], [Npr]"){
  GIVEN( "valid npr input values" ){
    std::vector<int> validValues{1, 2, 3};
    THEN( "the returned class has the correct value" ){
      for( auto& npr : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( npr ) ) );
        REQUIRE( npr == argument::extract< LEAPR::Card5::Npr >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid npr values" ){
    std::vector<int> invalidValues{0,-1};
    THEN( "an exception is thrown" ){
      for( auto& npr : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( npr ) ) );
	REQUIRE_THROWS( argument::extract< LEAPR::Card5::Npr >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
