#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card2 mtref input values",
  "[THERMR], [Card2], [Mtref]" ){
  GIVEN( "valid mtref tape values" ){
    std::vector<int> validValues{221, 222, 245, 249, 250};
    THEN( "the returned class has the correct tape value" ){
      for( auto mtref : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mtref ) ) );
        REQUIRE( mtref == argument::extract< 
          THERMR::Card2::Mtref >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mtref tape values" ){
    std::vector<int> invalidValues{219, 220, 251, 300};
    THEN( "an exception is thrown" ){
      for( auto mtref : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mtref ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Mtref >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
