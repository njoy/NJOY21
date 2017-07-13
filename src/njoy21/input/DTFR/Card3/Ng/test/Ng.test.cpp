#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ng values",
  "[DTFR],[Card3], [Ng]"){

  GIVEN( "valid ng values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( int ng : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ng ) ) );
        REQUIRE( ng == argument::extract< 
          DTFR::Card3::Ng >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid ng values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( int ng : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ng ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card3::Ng >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
