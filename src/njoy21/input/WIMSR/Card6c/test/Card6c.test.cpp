#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card6c",
          "[WIMSR] [Card6c]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 1.8 /" ) );

      WIMSR::Card6c card6c( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 9235 == card6c.identa.value );
        REQUIRE( Approx( 1.8 ) == card6c.yield.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 2.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6c( iss ) );
      }
    } // WHEN

    WHEN( "too few inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6c( iss ) );
      }
    } // WHEN

    WHEN( "too many inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 1.8 22 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6c( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
