#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card3",
          "[POWR] [Lib3] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 19410000 2 1 2 1 0/" ) );

      POWR::Lib3::Card3 card3( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 1 == card3.nlib.value );
        REQUIRE( 19410000 == card3.idat.value );
        REQUIRE( 2 == card3.newmat.value );
        REQUIRE( 1 == card3.iopt.value );
        REQUIRE( 2 == card3.mode.value );
        REQUIRE( 1 == card3.if5.value );
        REQUIRE( 0 == card3.if4.value );
      }
    } // WHEN

    WHEN( "the defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 2 30090101 3 0/" ) );

      POWR::Lib3::Card3 card3( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 2 == card3.nlib.value );
        REQUIRE( 30090101 == card3.idat.value );
        REQUIRE( 3 == card3.newmat.value );
        REQUIRE( 0 == card3.iopt.value );
        REQUIRE( 0 == card3.mode.value );
        REQUIRE( 0 == card3.if5.value );
        REQUIRE( 1 == card3.if4.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 2 19410000 2/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card3( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 19410000 2 1 2 1 0 0/"));

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 1 1 1/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
