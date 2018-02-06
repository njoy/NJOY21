#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card14 nd input values",
  "[LEAPR], [Card14], [Nd]" ){
  GIVEN( "valid nd values" ){
    std::vector<int> validValues{0, 1, 2, 99};
    THEN( "the returned class has the correct tape value" ){
      for( auto& nd : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nd ) ) );
        REQUIRE(nd == argument::extract< 
          LEAPR::Card14::Nd >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nd values" ){
    std::vector<int> invalidValues{-1, -100};
    THEN( "an exception is thrown" ){
      for( auto& nd : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nd ) ) );
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card14::Nd>( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

