#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR, Card1",
          "[MIXR] [Card1]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a simple input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 24 -23 -22 -21 /" ) );

      THEN( "the values can be verified" ){
        MIXR::Card1 card1( iss );

        REQUIRE( 24 == card1.nout.value );

        REQUIRE( -23 == card1.nin.at( 0 ).value );
        REQUIRE( -22 == card1.nin.at( 1 ).value );
        REQUIRE( -21 == card1.nin.at( 2 ).value );
      }
    }

    WHEN( "the maximum number of nin's are provided" ){
      iRecordStream<char> iss( std::istringstream(
                            " 20 -30 -31 -32 -33 -34 -35 -36 -37 -38 -39 /" ) );

      THEN( "the values can be verified" ){
        MIXR::Card1 card1( iss );

        REQUIRE( 20 == card1.nout.value );

        for( int i = 0; i < 10; i++ ){
          REQUIRE( ( -30 - i ) == card1.nin.at( i ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no nin values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 25 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "an nin value has the same absolute value as nout" ){
      iRecordStream<char> iss( std::istringstream( " 24 -27 -28 -24 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too many nin values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                   " 25 31 32 33 34 35 36 37 38 39 40 41 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided for nout" ){
      iRecordStream<char> iss( std::istringstream( " 19 25 26 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided for nin" ){
      iRecordStream<char> iss( std::istringstream( " 25 26 100 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card1( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
