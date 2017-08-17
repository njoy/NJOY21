#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card3 nphon input values", 
  "[LEAPR], [Card3], [Nphon]"){
  GIVEN( "valid Nphon parameters" ){
    std::vector<int> validValues = { 1, 50, 150 };
    THEN( "the returned class has the correct value" ){
      for( auto& nphon : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( nphon ) ) );
        REQUIRE( nphon == argument::extract< 
          LEAPR::Card3::Nphon > ( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "no nphon value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 100 == argument::extract< 
        LEAPR::Card3::Nphon >( iss ).value );
    } // THEN
  } // GIVEN
  GIVEN( "invalid Nphon parameters" ){
    std::vector<int> invalidValues{ -2, -1, 0 };
    THEN( "an exception is thrown" ){
      for( auto& nphon : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( nphon ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card3::Nphon >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
