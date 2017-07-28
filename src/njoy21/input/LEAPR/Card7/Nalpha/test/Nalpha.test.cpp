#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card7 nalpha input values", 
  "[LEAPR], [Card7], [Nalpha]"){
  GIVEN( "valid nalpha input values" ){
    std::vector<int> validValues{1, 2, 3};
    THEN( "the returned class has the correct value" ){
      for( auto& nalpha : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nalpha ) ) );
        REQUIRE( nalpha == argument::extract< 
          LEAPR::Card7::Nalpha >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid nalpha values" ){
    std::vector<int> invalidValues{0, -1};
    THEN( "an exception is thrown" ){
      for( auto& nalpha : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nalpha ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card7::Nalpha >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
