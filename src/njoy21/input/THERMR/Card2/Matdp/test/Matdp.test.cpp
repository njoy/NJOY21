#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card2 matdp input values",
  "[THERMR], [Card2], [Matdp]" ){
  GIVEN( "valid matdp tape values" ){
    std::vector<int> validValues{1, 125, 9998, 9999};

    THEN( "the returned class has the correct tape value" ){
      for( auto matdp : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( matdp ) ) );
        REQUIRE( matdp == argument::extract< 
          THERMR::Card2::Matdp >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid matdp tape values" ){
    std::vector<int> invalidValues{-20, -1, 0, 10000, 10001};

    THEN( "an exception is thrown" ){
      for( auto matdp : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( matdp ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Matdp >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
