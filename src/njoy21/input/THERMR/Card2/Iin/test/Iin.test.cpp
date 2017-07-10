#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR iin values",
  "[THERMR],[Card2], [Iin]"){

  GIVEN( "valid iin values" ){
    std::vector<int> validValues{0, 1, 2};
    THEN( "the returned class has the correct value" ){
      for( int iin : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( iin ) ) );
        REQUIRE( iin == argument::extract< 
          THERMR::Card2::Iin >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid iin values" ){
    std::vector<int> invalidValues{-1, 3};
    THEN( "an exception is thrown" ){
      for( int iin : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( iin ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Iin >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
