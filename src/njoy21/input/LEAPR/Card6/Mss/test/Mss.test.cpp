#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Mss input values", 
  "[LEAPR], [Card6], [Mss]"){
  GIVEN( "valid mss input values" ){
    std::vector<int> validValues{1, 2, 3};
    THEN( "the returned class has the correct value" ){
      for( auto& mss : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mss ) ) );
        REQUIRE( mss == argument::extract< LEAPR::Card6::Mss >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid mss values" ){
    std::vector<int> invalidValues{0,-1};
    THEN( "an exception is thrown" ){
      for( auto& mss : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mss ) ) );
	REQUIRE_THROWS( argument::extract< LEAPR::Card6::Mss >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
