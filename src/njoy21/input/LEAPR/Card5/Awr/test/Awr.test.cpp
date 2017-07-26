#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Awr input values", 
  "[LEAPR], [Card5],[Awr]"){
  GIVEN( "valid awr input values" ){
    std::vector<double> validValues{0.001, 23.0};
    THEN( "the returned class has the correct value" ){
      for( auto& awr : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( awr ) ) );
        REQUIRE( awr == argument::extract< LEAPR::Card5::Awr >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid awr values" ){
    std::vector<double> invalidValues{0,-0.001};
    THEN( "an exception is thrown" ){
      for( auto& awr : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( awr ) ) );
	REQUIRE_THROWS( argument::extract< LEAPR::Card5::Awr >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
