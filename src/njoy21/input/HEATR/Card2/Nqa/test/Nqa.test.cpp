#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR nqa values",
  "[HEATR], [Card2], [Nqa]"){

  GIVEN( "valid nqa inputs" ){
    WHEN( "nqa input provided" ){
      std::vector<int> validValues{0, 1, 15, 29, 30};
      THEN( "the returned nqa class has the correct value" ){
        for( int nqa : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( nqa ) ) );
          REQUIRE( nqa == argument::extract< 
            HEATR::Card2::Nqa >( iss ).value );
        } 
      } // THEN
    } // WHEN
    WHEN( "no nqa input value is given" ){
      iRecordStream<char> iss( std::istringstream( " / " ) );
      THEN( "the default value is used" ){
        REQUIRE( 0 == argument::extract<
          HEATR::Card2::Nqa >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "nqa input values are invalid" ){
    std::vector<int> invalidValues{-2, -1, 31, 32};
    THEN( "an exception is thrown" ){
      for( int nqa : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( nqa ) ) );
        REQUIRE_THROWS( argument::extract< 
          HEATR::Card2::Nqa >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
