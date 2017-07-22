#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card2 natom input values",
  "[THERMR], [Card2], [Natom]" ){
  GIVEN( "valid natom tape values" ){
    std::vector<int> validValues{1, 2, 10};

    THEN( "the returned class has the correct tape value" ){
      for( auto natom : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( natom ) ) );
        REQUIRE( natom == argument::extract< 
          THERMR::Card2::Natom >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid natom tape values" ){
    std::vector<int> invalidValues{0, -1, -10};

    THEN( "an exception is thrown" ){
      for( auto natom : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( natom ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Natom >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
