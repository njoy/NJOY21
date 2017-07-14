#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR nqa values",
  "[HEATR],[Card2], [Nqa]"){

  GIVEN( "valid nqa inputs" ){
    std::vector<int> validValues{0, 1, 15, 29, 30};
    THEN( "the returned nqa class has the correct value" ){
      for( int nqa : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( nqa ) ) );
        REQUIRE( nqa == argument::extract< 
          HEATR::Card2::Nqa >( iss ).value );
      } 
    } // THEN
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

  GIVEN( "no nqa input value is given" ){
    THEN( "the default value is used" ){ 
      iRecordStream<char> iss( std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract<
        HEATR::Card2::Nqa >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
