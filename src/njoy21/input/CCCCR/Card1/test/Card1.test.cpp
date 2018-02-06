#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card1",
          "[CCCCR] [Card1]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 25 -29 -30 -31 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::Card1 card1( iss );

        REQUIRE( 25 == card1.nin.value );
        REQUIRE( -29 == card1.nisot.value );
        REQUIRE( -30 == card1.nbrks.value );
        REQUIRE( -31 == card1.ndlay.value );
      }
    } // WHEN

    WHEN( "no extra values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 22 /" ) );

      THEN( "the default values can be provided" ){
        CCCCR::Card1 card1( iss );

        REQUIRE( 22 == card1.nin.value );
        REQUIRE( 0 == card1.nisot.value );
        REQUIRE( 0 == card1.nbrks.value );
        REQUIRE( 0 == card1.ndlay.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 28 -29 3 -31 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 25 -29 -30 -31 -32 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card1( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
