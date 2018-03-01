#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card2",
          "[ERRORR] [Normal] [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 600 12 4 0 0 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card2 card2( iss );

        REQUIRE( 600 == card2.matd.value );
        REQUIRE( 12 == card2.ign.value );
        REQUIRE( 4 == card2.iwt.value );
        REQUIRE( 0 == card2.iprint.value );
        REQUIRE( 0 == card2.irelco.value );
      }
    } // WHEN

    WHEN( "all defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 610 /" ) );

      THEN( "the default values can be verified" ){
        ERRORR::Normal::Card2 card2( iss );

        REQUIRE( 610 == card2.matd.value );
        REQUIRE( 1 == card2.ign.value );
        REQUIRE( 6 == card2.iwt.value );
        REQUIRE( 1 == card2.iprint.value );
        REQUIRE( 1 == card2.irelco.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card2( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 600 12 4 0 0 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card2( iss ) );
      }
    } // WHEN

    WHEN( "a value is invalid" ){
      iRecordStream<char> iss( std::istringstream( " 600 12 -1 0 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card2( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
