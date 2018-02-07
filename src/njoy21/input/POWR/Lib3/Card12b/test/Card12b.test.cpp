#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card12b",
          "[POWR] [Lib3] [Card12b]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 12 215 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card12b card12b( iss, 256 );

        REQUIRE( 12 == card12b.ia.value );
        REQUIRE( 12 == card12b.l1.value );
        REQUIRE( 215 == card12b.l2.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 12 215 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12b( iss, 256 ) );
      }
    } // WHEN

    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12b( iss, 256 ) );
      }
    } // WHEN

    WHEN( "l1 and l2 are reversed" ){
      iRecordStream<char> iss( std::istringstream( " 12 215 12 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12b( iss, 256 ) );
      }
    } // WHEN

    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " -12 12 215 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12b( iss, 256 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
