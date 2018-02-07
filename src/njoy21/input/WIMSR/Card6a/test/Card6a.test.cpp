#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card6a",
          "[WIMSR] [Card6a]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 816 0.8 /" ) );

      WIMSR::Card6a card6a( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 816 == card6a.identa.value );
        REQUIRE( Approx( 0.8 ) == card6a.yield.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 10000 0.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6a( iss ) );
      }
    } // WHEN

    WHEN( "too few values are given" ){
      iRecordStream<char> iss( std::istringstream( " 816 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6a( iss ) );
      }
    } // WHEN

    WHEN( "too many arguments are given" ){
      iRecordStream<char> iss( std::istringstream( " 816 0.8 1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card6a( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
