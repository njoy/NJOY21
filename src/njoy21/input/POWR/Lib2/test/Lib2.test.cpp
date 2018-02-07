#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2",
          "[POWR] [Lib2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "material is set to zero" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the value can be verified and the rest are unused" ){
        POWR::Lib2 lib2( iss );

        REQUIRE( 0 == lib2.card3.matd.value );
        REQUIRE( std::nullopt == lib2.card3.rest );
        REQUIRE( std::nullopt == lib2.card45 );
      }
    } // WHEN

    WHEN( "a normal material is provided, but that's it" ){
      iRecordStream<char> iss( std::istringstream( " 1234 /\n /\n /" ) );

      THEN( "the default values can be verified" ){
        POWR::Lib2 lib2( iss );

        REQUIRE( 1234 == lib2.card3.matd.value );
        REQUIRE( 300*dimwits::kelvin == lib2.card3.rest->first.value );
        REQUIRE( "" == lib2.card3.rest->second.value );

        REQUIRE( 0 == lib2.card45->first.itrc.value );
        REQUIRE( 0 == lib2.card45->first.mti.value );
        REQUIRE( 0 == lib2.card45->first.mtc.value );

        REQUIRE( Approx( 0.0 ) == lib2.card45->second.xi.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.alpha.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.mubar.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.nu.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.kappaFission.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.kappaCapture.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.lambda.value );
        REQUIRE( Approx( 0.0 ) == lib2.card45->second.sigmaS.value );
      }
    } // WHEN

    WHEN( "all values are provided" ){
      std::string inp(
 std::string( " 2345 3.14 'hollerith' /\n" ) +
 std::string( " 1 2 3 /\n" ) +
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR::Lib2 lib2( iss );

        REQUIRE( 2345 == lib2.card3.matd.value );
        REQUIRE( 3.14*dimwits::kelvin == lib2.card3.rest->first.value );
        REQUIRE( "hollerith" == lib2.card3.rest->second.value );

        REQUIRE( 1 == lib2.card45->first.itrc.value );
        REQUIRE( 2 == lib2.card45->first.mti.value );
        REQUIRE( 3 == lib2.card45->first.mtc.value );

        REQUIRE( Approx( 0.1 ) == lib2.card45->second.xi.value );
        REQUIRE( Approx( 0.2 ) == lib2.card45->second.alpha.value );
        REQUIRE( Approx( 0.3 ) == lib2.card45->second.mubar.value );
        REQUIRE( Approx( 0.4 ) == lib2.card45->second.nu.value );
        REQUIRE( Approx( 0.5 ) == lib2.card45->second.kappaFission.value );
        REQUIRE( Approx( 0.6 ) == lib2.card45->second.kappaCapture.value );
        REQUIRE( Approx( 0.7 ) == lib2.card45->second.lambda.value );
        REQUIRE( Approx( 0.8 ) == lib2.card45->second.sigmaS.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid material is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2( iss ) );
      }
    } // WHEN

    WHEN( "no values are given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
