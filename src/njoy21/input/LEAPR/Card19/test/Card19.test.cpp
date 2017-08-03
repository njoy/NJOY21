#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card19 input values", 
  "[LEAPR], [Card19]"){
  GIVEN( "valid card19 input values" ){
    std::vector<double> validValues = { 0.0, 0.1, 0.9, 1.0 };
    THEN( "the returned class has the correct value" ){
      for( auto& val : validValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( val ) ) );
        LEAPR::Card19 card19( iss );
	REQUIRE( card19.cfrac.value == val );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid card19 input values" ){
    std::vector<double> invalidValues = { -0.1, 1.1 };
    THEN( "an exception is thrown" ){
      for( auto& val : invalidValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( val ) ) );
        REQUIRE_THROWS( LEAPR::Card19( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

