#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card13b",
          "[ERRORR] [Normal] [Card13b]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e6 2e6 3e6 4e6 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card13b card13b( iss );

        REQUIRE( 1e6*dimwits::electronVolt == card13b.eb.value );
        REQUIRE( 2e6*dimwits::electronVolt == card13b.tb.value );
        REQUIRE( 3e6*dimwits::electronVolt == card13b.ec.value );
        REQUIRE( 4e6*dimwits::electronVolt == card13b.tc.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e6 2e6 3e6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card13b( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e6 2e6 3e6 4e6 5e6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card13b( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e6 2e6 -3e6 4e6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card13b( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
