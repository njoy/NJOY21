#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Twt input values", 
  "[LEAPR], [Card13], [Twt]"){
  GIVEN( "valid twt input values" ){
    std::vector<double> validValues{0.0, 1.0, 2.0, 3.0};
    THEN( "the returned class has the correct value" ){
      for( auto& twt : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( twt ) ) );
        REQUIRE( twt == argument::extract< 
          LEAPR::Card13::Twt >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid twt values" ){
    std::vector<double> invalidValues{-0.1, -1.0};
    THEN( "an exception is thrown" ){
      for( auto& twt : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( twt ) ) );
	REQUIRE_THROWS( argument::extract< 
          LEAPR::Card13::Twt >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
