#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card6",
          "[POWR] [Lib3] [Card6]" ){
  GIVEN( "valid inputs" ){
    WHEN ( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 0 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card6 card6( iss );

        REQUIRE( 0 == card6.ntis.value );
        REQUIRE( 0 == card6.nfis.value );
      }
    } // WHEN

    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 144 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card6 card6( iss );

        REQUIRE( 12 == card6.ntis.value );
        REQUIRE( 144 == card6.nfis.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card6( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 2 3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card6( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card6( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
