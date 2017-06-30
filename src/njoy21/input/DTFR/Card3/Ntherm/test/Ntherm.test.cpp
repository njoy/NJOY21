#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ntherm values",
  "[DTFR],[Card3], [Ntherm]"){

  GIVEN( "valid ntherm inputs" ){
    std::vector<int> validValues{0, 1, 15};
    THEN( "the returntherm class has the correct value" ){
      for( int ntherm : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ntherm ) ) );
        REQUIRE( ntherm == argument::extract< 
          DTFR::Card3::Ntherm >( iss ).value );
      } 
    } // THEN
  } // GIVEN

  GIVEN( "ntherm input values are invalid" ){
    std::vector<int> invalidValues{-2, -1};
    THEN( "an exception is thrown" ){
      for( int ntherm : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( ntherm ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card3::Ntherm >( iss ) );
      }
    } // THEN
  } // GIVEN

  GIVEN( "no ntherm input value is given" ){
    THEN( "the default value is used" ){ 
      iRecordStream<char> iss( std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract<
        DTFR::Card3::Ntherm >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
