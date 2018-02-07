#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card5",
          "[POWR] [Lib2] [Card5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                        " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8/" ) );

      POWR::Lib2::Card5 card5( iss );

      THEN( "the values can be verified" ){
        REQUIRE( Approx( 0.1 ) == card5.xi.value );
        REQUIRE( Approx( 0.2 ) == card5.alpha.value );
        REQUIRE( Approx( 0.3 ) == card5.mubar.value );
        REQUIRE( Approx( 0.4 ) == card5.nu.value );
        REQUIRE( Approx( 0.5 ) == card5.kappaFission.value );
        REQUIRE( Approx( 0.6 ) == card5.kappaCapture.value );
        REQUIRE( Approx( 0.7 ) == card5.lambda.value );
        REQUIRE( Approx( 0.8 ) == card5.sigmaS.value );
      }
    } // WHEN

    WHEN( "few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3/" ) );

      POWR::Lib2::Card5 card5( iss );

      THEN( "the values can be verified" ){
        REQUIRE( Approx( 0.1 ) == card5.xi.value );
        REQUIRE( Approx( 0.2 ) == card5.alpha.value );
        REQUIRE( Approx( 0.3 ) == card5.mubar.value );
        REQUIRE( Approx( 0.0 ) == card5.nu.value );
        REQUIRE( Approx( 0.0 ) == card5.kappaFission.value );
        REQUIRE( Approx( 0.0 ) == card5.kappaCapture.value );
        REQUIRE( Approx( 0.0 ) == card5.lambda.value );
        REQUIRE( Approx( 0.0 ) == card5.sigmaS.value );
      }
    } // WHEN

    WHEN( "no values are given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      POWR::Lib2::Card5 card5( iss );

      THEN( "the values can be verified" ){
        REQUIRE( Approx( 0.0 ) == card5.xi.value );
        REQUIRE( Approx( 0.0 ) == card5.alpha.value );
        REQUIRE( Approx( 0.0 ) == card5.mubar.value );
        REQUIRE( Approx( 0.0 ) == card5.nu.value );
        REQUIRE( Approx( 0.0 ) == card5.kappaFission.value );
        REQUIRE( Approx( 0.0 ) == card5.kappaCapture.value );
        REQUIRE( Approx( 0.0 ) == card5.lambda.value );
        REQUIRE( Approx( 0.0 ) == card5.sigmaS.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                    " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2::Card5( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 -0.3/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2::Card5( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
