#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Awr input values", 
  "[MIXR],[Card5],[Awr]"){
  GIVEN( "valid awr input values" ){
    std::vector<float> validValues{233.024800};
    THEN( "the returned class has the correct value" ){
      for( auto& awr : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( awr ) ) );
        REQUIRE( awr == argument::extract< MIXR::Card5::Awr >( iss ).value );
      }
    }
  }
  GIVEN( "invalid awr values" ){
    std::vector<float> invalidValues{0,-0.01};
    THEN( "an exception is thrown" ){
      for( auto& awr : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( awr ) ) );
	REQUIRE_THROWS( argument::extract< MIXR::Card5::Awr >( iss ) );
      }
    }
  }
}
