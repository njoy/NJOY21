#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR, Card4",
          "[COVR] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9211 12 8433 1 /" ) );

      THEN( "the values can be verified" ){
        COVR::Card4 card4( iss );

        REQUIRE( 9211 == card4.mat.value );
        REQUIRE( 12 == card4.mt.value );
        REQUIRE( 8433 == card4.mat1.value );
        REQUIRE( 1 == card4.mt1.value );
      }
    } // WHEN

    WHEN( "negative values are used for all but mat" ){
      iRecordStream<char> iss( std::istringstream( " 9211 -4 -1111 -98 /" ) );

      THEN( "the values can be verified" ){
        COVR::Card4 card4( iss );

        REQUIRE( 9211 == card4.mat.value );
        REQUIRE( -4 == card4.mt.value );
        REQUIRE( -1111 == card4.mat1.value );
        REQUIRE( -98 == card4.mt1.value );
      }
    } // WHEN

    WHEN( "all of the defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 9211 /" ) );

      THEN( "the default values can be verified" ){
        COVR::Card4 card4( iss );

        REQUIRE( 9211 == card4.mat.value );
        REQUIRE( 0 == card4.mt.value );
        REQUIRE( 0 == card4.mat1.value );
        REQUIRE( 0 == card4.mt1.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card4( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9211 1 1234 2 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card4( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 9211 1 -10000 2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card4( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
