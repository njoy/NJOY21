#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ncase output values",
  "[COVR], [Card3a], [Ncase]"){
  GIVEN( "valid inputs for ncase" ){
    WHEN( "the ncase value is provided" ){
      std::vector<int> validValues{1, 59, 60};
      THEN( "the returned class has the correct tape value" ){
        for( auto& ncase : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ncase ) ) );
          REQUIRE( ncase == argument::extract< 
            COVR::Card3a::Ncase >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no ncase value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 1 == argument::extract<
          COVR::Card3a::Ncase > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "ncase tapes are out of range" ){
      std::vector<int> invalidValues{0, -1, 61, 62};
      THEN( "an exception is thrown" ){
        for( auto& ncase : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ncase ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card3a::Ncase>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

