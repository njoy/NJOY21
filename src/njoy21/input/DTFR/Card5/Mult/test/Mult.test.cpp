#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR mult values",
  "[DTFR],[Card5], [Mult]"){

  GIVEN( "valid mult  values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( int mult : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mult ) ) );
        REQUIRE( mult == argument::extract< 
          DTFR::Card5::Mult >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mult values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( int mult : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mult ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card5::Mult >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
