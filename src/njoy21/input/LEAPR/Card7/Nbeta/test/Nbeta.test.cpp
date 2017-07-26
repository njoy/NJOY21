#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nbeta input values", 
  "[LEAPR], [Card7], [Nbeta]"){
  GIVEN( "valid nbeta input values" ){
    std::vector<int> validValues{1, 2, 3};
    THEN( "the returned class has the correct value" ){
      for( auto& nbeta : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nbeta ) ) );
        REQUIRE( nbeta == argument::extract< 
          LEAPR::Card7::Nbeta >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid nbeta values" ){
    std::vector<int> invalidValues{0,-1};
    THEN( "an exception is thrown" ){
      for( auto& nbeta : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nbeta ) ) );
	REQUIRE_THROWS( argument::extract< 
          LEAPR::Card7::Nbeta >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
