#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card8",
          "[ERRORR] [Rest] [Card8]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 34 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Rest::Card8 card8( iss );

        REQUIRE( 12 == card8.nmt.value );
        REQUIRE( 34 == card8.nek.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card8( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 34 50 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card8( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 51 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card8( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
