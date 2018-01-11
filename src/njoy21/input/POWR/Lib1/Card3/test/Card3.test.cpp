#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card3",
          "[POWR] [Lib1] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 301.0 0 12 2.1 / " ));

      POWR::Card3 card3( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 9235 == card3.matd.value );
        REQUIRE( 301.0*dimwits::kelvin == card3.rtemp.value );
        REQUIRE( 0 == card3.iff.value );
        REQUIRE( 12 == card3.nsgz.value );
        REQUIRE( Approx( 2.1 ) == card3.izref.value );
      }
    } // WHEN

    WHEN( "all defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 9235 /" ) );

      POWR::Card3 card3( iss );

      THEN( "the default values can be verified" ){
        REQUIRE( 9235 == card3.matd.value );
        REQUIRE( 300.0*dimwits::kelvin == card3.rtemp.value );
        REQUIRE( 1 == card3.iff.value );
        REQUIRE( 0 == card3.nsgz.value );
        REQUIRE( Approx( 1.0 ) == card3.izref.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "there are no values provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Card3( iss ) );
      }
    } // WHEN

    WHEN( "there are too many values" ){
      iRecordStream<char> iss( std::istringstream( " 9235 1.0 0 12 2.1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 -1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
