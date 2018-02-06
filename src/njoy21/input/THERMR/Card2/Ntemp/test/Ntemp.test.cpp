#define CATCH_CONFIG_MAIN
#include <numeric>
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ntemp output values", 
  "[THERMR],[Card2], [Ntemp]"){
  GIVEN( "valid ntemp parameters" ){
    std::vector<int> validValues = { 2, 4, 10, 50 };
    WHEN( "ntemp value provided" ){
      THEN( "the returned class has the correct value" ){
        for( int ntemp : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( ntemp ) ) );
          REQUIRE( ntemp == argument::extract< 
            THERMR::Card2::Ntemp > ( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no ntemp value provided" ){
      THEN( "the default value is returned" ){
        iRecordStream<char> iss( std::istringstream( "/") );
        REQUIRE( 1 == argument::extract< 
          THERMR::Card2::Ntemp >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid ntemp parameters" ){
    std::vector<int> invalidValues{ -2, -1, 0 };
    THEN( "an exception is thrown" ){
      for( auto ntemp : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ntemp ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card2::Ntemp >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
