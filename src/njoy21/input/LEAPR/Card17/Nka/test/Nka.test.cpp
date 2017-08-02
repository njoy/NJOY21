#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card17 nka input values",
  "[LEAPR], [Card17], [Nka]" ){
  GIVEN( "valid nka values" ){
    std::vector<int> validValues{0, 1, 2, 99};
    THEN( "the returned class has the correct tape value" ){
      for( auto& nka : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nka ) ) );
        REQUIRE(nka == argument::extract< 
          LEAPR::Card17::Nka >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nka values" ){
    std::vector<int> invalidValues{-1, -100};
    THEN( "an exception is thrown" ){
      for( auto& nka : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nka ) ) );
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card17::Nka>( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

