#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR icoh values",
  "[THERMR],[Card2], [Icoh]"){

  GIVEN( "valid icoh values" ){
    std::vector<int> validValues{0, 1, 2, 3, 11, 12, 13};
    THEN( "the returned class has the correct value" ){
      for( int icoh : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( icoh ) ) );
        REQUIRE( icoh == argument::extract< 
          THERMR::Card2::Icoh >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid icoh values" ){
    std::vector<int> invalidValues{-1, 4, 10, 14};
    THEN( "an exception is thrown" ){
      for( int icoh : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( icoh ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Icoh >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
