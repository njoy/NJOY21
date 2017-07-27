#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ni input values", 
  "[LEAPR], [Card11], [Ni]"){
  GIVEN( "valid ni input values" ){
    std::vector<int> validValues{1, 2, 3};
    THEN( "the returned class has the correct value" ){
      for( auto& ni : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( ni ) ) );
        REQUIRE( ni == argument::extract< LEAPR::Card11::Ni >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid ni values" ){
    std::vector<int> invalidValues{0,-1};
    THEN( "an exception is thrown" ){
      for( auto& ni : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( ni ) ) );
	REQUIRE_THROWS( argument::extract< LEAPR::Card11::Ni >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
