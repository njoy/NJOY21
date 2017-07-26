#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Aws input values", 
  "[LEAPR], [Card6],[Aws]"){
  GIVEN( "valid aws input values" ){
    std::vector<double> validValues{0.001, 23.0};
    THEN( "the returned class has the correct value" ){
      for( auto& aws : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( aws ) ) );
        REQUIRE( aws == argument::extract< LEAPR::Card6::Aws >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid aws values" ){
    std::vector<double> invalidValues{0,-0.001};
    THEN( "an exception is thrown" ){
      for( auto& aws : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( aws ) ) );
	REQUIRE_THROWS( argument::extract< LEAPR::Card6::Aws >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
