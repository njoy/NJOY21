#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card5 iel input values", 
  "[LEAPR], [Card5], [Iel]"){
  GIVEN( "valid iel input values" ){
    WHEN( "iel input provided" ){
      std::vector<int> validValues{0, 1, 5, 6};
      THEN( "the returned class has the correct value" ){
        for( auto& iel : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( iel ) ) );
          REQUIRE( iel == argument::extract< LEAPR::Card5::Iel >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no ield input provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      THEN( "default value is used" ){
        REQUIRE( 0 == argument::extract< LEAPR::Card5::Iel >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid iel values" ){
    std::vector<int> invalidValues{-1, 7};
    THEN( "an exception is thrown" ){
      for( auto& iel : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( iel ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card5::Iel >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
