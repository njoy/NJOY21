#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card12a",
          "[ERRORR] [Normal] [Card12a]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 /" ) );

      THEN( "the value can be verified" ){
        ERRORR::Normal::Card12a card12a( iss );

        REQUIRE( 12 == card12a.ngn.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card12a( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 13 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card12a( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card12a( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
