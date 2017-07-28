#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card1 nout input values",
  "[LEAPR], [Card1], [Nout]" ){
  GIVEN( "valid nout tape values" ){
    std::vector<int> validValues{-20, 20, 42, 99, -99};
    THEN( "the returned class has the correct tape value" ){
      for( auto nout : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nout ) ) );
        REQUIRE(nout == argument::extract< 
          LEAPR::Card1::Nout >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nout tape values" ){
    std::vector<int> invalidValues{-19, 19, -1, 1, 100, -100};
    THEN( "an exception is thrown" ){
      for( auto nout : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nout ) ) );
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card1::Nout>( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

