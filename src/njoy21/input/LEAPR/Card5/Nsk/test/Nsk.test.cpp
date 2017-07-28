#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card5 nsk input values", 
  "[LEAPR], [Card5], [Nsk]"){
  GIVEN( "valid nsk input values" ){
    WHEN( "nsk input provided" ){
      std::vector<int> validValues{0, 1, 2};
      THEN( "the returned class has the correct value" ){
        for( auto& nsk : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nsk ) ) );
          REQUIRE( nsk == argument::extract< LEAPR::Card5::Nsk >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no nsk input provided" ){
      iRecordStream<char> iss( std::istringstream( "/ " ) );
      THEN( "default value is used" ){
        REQUIRE( 0 == argument::extract< LEAPR::Card5::Nsk >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid nsk values" ){
    std::vector<int> invalidValues{-1, 3};
    THEN( "an exception is thrown" ){
      for( auto& nsk : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nsk ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card5::Nsk >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
