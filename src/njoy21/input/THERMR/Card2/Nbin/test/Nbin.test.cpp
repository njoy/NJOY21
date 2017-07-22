#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card2 nbin input values",
  "[THERMR], [Card2], [Nbin]" ){
  GIVEN( "valid nbin input values" ){
    std::vector<int> validValues{1, 2, 10};

    THEN( "the returned class has the correct tape value" ){
      for( auto nbin : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nbin ) ) );
        REQUIRE( nbin == argument::extract< 
          THERMR::Card2::Nbin >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nbin input values" ){
    std::vector<int> invalidValues{0, -1, -2, -10};

    THEN( "an exception is thrown" ){
      for( auto nbin : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nbin ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Nbin >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
