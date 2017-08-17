#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card4 Za input values", 
  "[LEAPR], [Card4], [Za]"){
  GIVEN( "valid za value" ){
    std::vector<long> validValues{1001, 26000, 199999 };
    THEN( "the returned class has the correct value" ){
      for( auto& za : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( za ) ) );
        REQUIRE( za == argument::extract< LEAPR::Card4::Za >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid za value" ){
    std::vector<long> invalidValues{-1, 1000, 200000, 200001};
    THEN( "an exception is thrown" ){
      for( auto& za : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( za ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card4::Za >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
