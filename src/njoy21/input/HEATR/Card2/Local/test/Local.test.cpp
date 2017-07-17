#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR local values",
  "[HEATR], [Card2], [Local]"){

  GIVEN( "valid local inputs" ){
    WHEN( "local input provided" ){
      std::vector<int> validValues{0, 1};
      THEN( "the returned local class has the correct value" ){
        for( int local : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( local ) ) );
          REQUIRE( local == argument::extract< 
            HEATR::Card2::Local >( iss ).value );
        } 
      } // THEN
    } // WHEN
    WHEN( "no local input provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      THEN( "the default value is used" ){
        REQUIRE( 0 == argument::extract<
          HEATR::Card2::Local >( iss ).value );
      } // THEN
    } // WHEN      
  } // GIVEN

  GIVEN( "local input values are invalid" ){
    std::vector<int> invalidValues{-2, -1, 3};
    THEN( "an exception is thrown" ){
      for( int local : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( local ) ) );
        REQUIRE_THROWS( argument::extract< 
          HEATR::Card2::Local >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
