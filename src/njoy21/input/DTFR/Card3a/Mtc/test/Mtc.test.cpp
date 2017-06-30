#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR mtc values",
  "[DTFR],[Card3a], [Mtc]"){
  GIVEN( "valid mtc values" ){
    std::vector<int> validValues{0, 1, 456, 999};
    THEN( "the returned class has the correct value" ){
      for( int mtc : validValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( mtc ) ) );
        REQUIRE( mtc == argument::extract< DTFR::Card3a::Mtc >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mtc values" ){
    std::vector<int> invalidValues{-1, 1000};
    THEN( "an exception is thrown" ){
      for( int mtc : invalidValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( mtc ) ) );
        REQUIRE_THROWS( argument::extract< DTFR::Card3a::Mtc >( iss ) );
      }
    } // THEN
  } // GIVEN
  
  GIVEN( "no mtc value provided" ){
    THEN( "default value used" ){
      iRecordStream<char> iss( 
        std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< DTFR::Card3a::Mtc >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
