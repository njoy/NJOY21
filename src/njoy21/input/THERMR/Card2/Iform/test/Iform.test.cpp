#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR iform values",
  "[THERMR],[Card2], [Iform]"){

  GIVEN( "valid iform values" ){
    std::vector<int> validValues{0, 1};
    THEN( "the returned class has the correct value" ){
      for( int iform : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( iform ) ) );
        REQUIRE( iform == argument::extract< 
          THERMR::Card2::Iform >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid iform values" ){
    std::vector<int> invalidValues{-1, 2};
    THEN( "an exception is thrown" ){
      for( int iform : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( iform ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Iform >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
