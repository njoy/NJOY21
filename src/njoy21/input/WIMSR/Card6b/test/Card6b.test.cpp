#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card6b",
          "[WIMSR] [Card6b]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 101 0.2 /" ) );

      WIMSR::Card6b card6b( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 101 == card6b.identa.value );
        REQUIRE( Approx( 0.2 ) == card6b.lambda.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 0.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6b( iss ) );
      }
    } // WHEN

    WHEN( "an input is missing" ){
      iRecordStream<char> iss( std::istringstream( " 101 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6b( iss ) );
      }
    } // WHEN

    WHEN( "too many inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 101 0.2 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6b( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
