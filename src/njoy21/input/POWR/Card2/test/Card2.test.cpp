#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Card2",
          "[POWR] [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 0 1 /" ) );

      POWR::Card2 card2( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 1 == card2.lib.value );
        REQUIRE( 0 == card2.iprint.value );
        REQUIRE( 1 == card2.iclaps.value );
      }
    } // WHEN

    WHEN( "the defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 2 /" ) );

      POWR::Card2 card2( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 2 == card2.lib.value );
        REQUIRE( 0 == card2.iprint.value );
        REQUIRE( 0 == card2.iclaps.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Card2( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 2 2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Card2( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
