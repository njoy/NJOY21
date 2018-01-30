#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card4",
          "[CCCCR] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 29 -10 3 5 2 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::Card4 card4( iss );

        REQUIRE( 29 == card4.ngroup.value );
        REQUIRE( -10 == card4.nggrup.value );
        REQUIRE( 3 == card4.niso.value );
        REQUIRE( 5 == card4.maxord.value );
        REQUIRE( 2 == card4.ifopt.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 29 -10 3 5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card4( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 29 -10 3 5 2 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card4( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 29 -10 -1 5 2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card4( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
