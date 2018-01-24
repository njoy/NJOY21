#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card3",
          "[POWR] [Lib2] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 301.0 '123'/" ) );

      POWR::Lib2::Card3 card3( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 9235 == card3.matd.value );
        REQUIRE( 301.0*dimwits::kelvin == card3.rest->second.value );
        REQUIRE( "123" == card3.rest->first.value );
      }
    } // WHEN

    WHEN( "the defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 9235 /" ) );

      POWR::Lib2::Card3 card3( iss );

      THEN( "the defaults can be verified" ){
        REQUIRE( 9235 == card3.matd.value );
        REQUIRE( 300.0*dimwits::kelvin == card3.rest->second.value );
        REQUIRE( "" == card3.rest->first.value );
      } // THEN
    } // WHEN

    WHEN( "the material is zero" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the value can be verified and the rest are unused" ){
        POWR::Lib2::Card3 card3( iss );

        REQUIRE( 0 == card3.matd.value );
        REQUIRE( std::nullopt == card3.rest );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
