#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR mt values",
  "[DTFR],[Card5], [Mt]"){

  GIVEN( "valid mt  values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( int mt : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mt ) ) );
        REQUIRE( mt == argument::extract< 
          DTFR::Card5::Mt >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mt values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( int mt : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mt ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card5::Mt >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
