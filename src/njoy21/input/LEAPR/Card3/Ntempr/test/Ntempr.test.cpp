#define CATCH_CONFIG_MAIN
#include <numeric>
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ntempr output values", 
  "[LEAPR], [Card3], [Ntempr]"){
  GIVEN( "valid Ntempr parameters" ){
    std::vector<int> validValues = { 2, 4, 10, 50 };
    THEN( "the returned class has the correct value" ){
      for( int ntempr : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ntempr ) ) );
        REQUIRE( ntempr == argument::extract< 
          LEAPR::Card3::Ntempr > ( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "no ntempr value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 1 == argument::extract< 
        LEAPR::Card3::Ntempr >( iss ).value );
    } // THEN
  } // GIVEN
  GIVEN( "invalid Ntempr parameters" ){
    std::vector<int> invalidValues{ -2, -1, 0 };
    THEN( "an exception is thrown" ){
      for( auto ntempr : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ntempr ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card3::Ntempr >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
