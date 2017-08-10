#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR mt values",
  "[COVR], [Card4], [Mt]"){

  GIVEN( "valid mt values" ){
    std::vector<int> validValues{0, 1, 2};
    WHEN( "mt value provided" ){
      THEN( "the returned class has the correct value" ){
        for( int mt : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( mt ) ) );
          REQUIRE( mt == argument::extract< 
            COVR::Card4::Mt >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no mt value provided" ){
      iRecordStream<char> iss( std::istringstream( " / " ) );
      THEN( "defaul value is used" ){
        REQUIRE( 0 == argument::extract<
          COVR::Card4::Mt >( iss ).value );
      } // THEN
    } // THEN
  } // GIVEN

  GIVEN( "invalid mt values" ){
    std::vector<int> invalidValues{-1, -2};
    THEN( "an exception is thrown" ){
      for( int mt : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mt ) ) );
        REQUIRE_THROWS( argument::extract< 
          COVR::Card4::Mt >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
