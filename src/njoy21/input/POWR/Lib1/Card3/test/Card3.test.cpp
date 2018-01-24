#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card3",
          "[POWR] [Lib1] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 301.0 0 12 2 / " ));

      POWR::Lib1::Card3 card3( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 9235 == card3.matd.value );
        REQUIRE( 301.0*dimwits::kelvin == std::get<0>( *( card3.rest ) ).value);
        REQUIRE( 0 == std::get<1>( *( card3.rest ) ).value );
        REQUIRE( 12 == std::get<2>( *( card3.rest) ).value );
        REQUIRE( 2 == std::get<3>( *( card3.rest ) ).value );
      }
    } // WHEN

    WHEN( "all defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 9235 /" ) );

      POWR::Lib1::Card3 card3( iss );

      THEN( "the default values can be verified" ){
        REQUIRE( 9235 == card3.matd.value );
        REQUIRE( 300.0*dimwits::kelvin == std::get<0>( *( card3.rest ) ).value);
        REQUIRE( 1 == std::get<1>( *( card3.rest ) ).value );
        REQUIRE( 0 == std::get<2>( *( card3.rest ) ).value );
        REQUIRE( 1 == std::get<3>( *( card3.rest ) ).value );
      }
    } // WHEN

    WHEN( "a zero material value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the value can be verified and the rest are unused" ){
        POWR::Lib1::Card3 card3( iss );

        REQUIRE( 0 == card3.matd.value );
        REQUIRE( std::nullopt == card3.rest );
      }
    } // WHEN

    WHEN( "a negative material value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -9235 /" ) );

      THEN( "the value can be verified and the rest are unused" ){
        POWR::Lib1::Card3 card3( iss );

        REQUIRE( -9235 == card3.matd.value );
        REQUIRE( std::nullopt == card3.rest );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "there are no values provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card3( iss ) );
      }
    } // WHEN

    WHEN( "there are too many values" ){
      iRecordStream<char> iss( std::istringstream( " 9235 1.0 0 12 2 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 9235 -1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card3( iss ) );
      }
    } // WHEN

    WHEN( "too many values are given with a zero matd" ){
      iRecordStream<char> iss( std::istringstream( " 0 1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card3( iss ) );
      }
    } // WHEN

    WHEN( "too many values are given with a negative matd" ){
      iRecordStream<char> iss( std::istringstream( " -9235 1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
