#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card4",
          "[WIMSR] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 0 0 1.0 0 0 /" ) );

      WIMSR::Card4 card4( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 0 == card4.ntemp.value );
        REQUIRE( 0 == card4.nsigz.value );
        REQUIRE( Approx( 1.0 ) == card4.sgref.value );
        REQUIRE( 0 == card4.ires.value );
        REQUIRE( 0.0 == card4.sigp.value );
        REQUIRE( 0 == card4.mti.value );
        REQUIRE( 0 == card4.mtc.value );
        REQUIRE( 1 == card4.ip1opt.value );
        REQUIRE( 0 == card4.inorf.value );
        REQUIRE( 0 == card4.isof.value );
        REQUIRE( 0 == card4.ifprod.value );
        REQUIRE( 0 == card4.jp1.value );
      } // THEN
    } // WHEN

    WHEN( "no defaults are used" ){
      iRecordStream<char> iss( std::istringstream(
                             " 12 8 1.5e10 3 201.0 221 0 0 1 1 2 1 /" ) );

      WIMSR::Card4 card4( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 12 == card4.ntemp.value );
        REQUIRE( 8 == card4.nsigz.value );
        REQUIRE( Approx( 1.5e10 ) == card4.sgref.value );
        REQUIRE( 3 == card4.ires.value );
        REQUIRE( 201.0 == card4.sigp.value );
        REQUIRE( 221 == card4.mti.value );
        REQUIRE( 0 == card4.mtc.value );
        REQUIRE( 0 == card4.ip1opt.value );
        REQUIRE( 1 == card4.inorf.value );
        REQUIRE( 1 == card4.isof.value );
        REQUIRE( 2 == card4.ifprod.value );
        REQUIRE( 1 == card4.jp1.value );
      } // THEN
    } // WHEN

    WHEN( "the example from test problem 11 is used" ){
      iRecordStream<char> iss( std::istringstream(
                             " 3 7 1e10 3 10.890 221 0 / " ) );

      WIMSR::Card4 card4( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 3 == card4.ntemp.value );
        REQUIRE( 7 == card4.nsigz.value );
        REQUIRE( Approx( 1e10 ) == card4.sgref.value );
        REQUIRE( 3 == card4.ires.value );
        REQUIRE( Approx( 10.890 ) == card4.sigp.value );
        REQUIRE( 221 == card4.mti.value );
        REQUIRE( 0 == card4.mtc.value );
        REQUIRE( 1 == card4.ip1opt.value );
        REQUIRE( 0 == card4.inorf.value );
        REQUIRE( 0 == card4.isof.value );
        REQUIRE( 0 == card4.ifprod.value );
        REQUIRE( 0 == card4.jp1.value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "no input is provided for a value with no default" ){
      iRecordStream<char> iss( std::istringstream( " 3 7 1e10 3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card4( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                             " 12 8 1.5e10 3 201.0 221 0 0 1 1 2 1 2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card4( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
