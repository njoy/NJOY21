#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR ntemp values",
  "[HEATR], [Card2], [Ntemp]"){

  GIVEN( "valid ntemp inputs" ){
    WHEN( "ntemp value provided" ){
      std::vector<int> validValues{0, 1, 15};
      THEN( "the returned ntemp class has the correct value" ){
        for( int ntemp : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( ntemp ) ) );
          REQUIRE( ntemp == argument::extract< 
            HEATR::Card2::Ntemp >( iss ).value );
        } 
      } // THEN
    } // WHEN
    WHEN( "no ntemp value provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      THEN( "the default value is used" ){ 
        REQUIRE( 0 == argument::extract<
          HEATR::Card2::Ntemp >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "ntemp input values are invalid" ){
    std::vector<int> invalidValues{-2, -1};
    THEN( "an exception is thrown" ){
      for( int ntemp : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ntemp ) ) );
        REQUIRE_THROWS( argument::extract< 
          HEATR::Card2::Ntemp >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
