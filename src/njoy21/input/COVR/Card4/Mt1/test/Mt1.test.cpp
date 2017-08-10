#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR mt1 values",
  "[COVR], [Card4], [Mt1]"){

  GIVEN( "valid mt1 values" ){
    std::vector<int> validValues{0, 1, 2};
    WHEN( "mt1 value provided" ){
      THEN( "the returned class has the correct value" ){
        for( int mt1 : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( mt1 ) ) );
          REQUIRE( mt1 == argument::extract< 
            COVR::Card4::Mt1 >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no mt1 value provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      THEN( "default value is used" ){
        REQUIRE( 0 == argument::extract<
          COVR::Card4::Mt1 >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid mt1 values" ){
    std::vector<int> invalidValues{-1, -2};
    THEN( "an exception is thrown" ){
      for( int mt1 : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mt1 ) ) );
        REQUIRE_THROWS( argument::extract< 
          COVR::Card4::Mt1 >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
