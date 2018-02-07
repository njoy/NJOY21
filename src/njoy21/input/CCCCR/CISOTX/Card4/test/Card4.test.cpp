#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card4",
          "[CCCCR] [CISOTX] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                           " -10 1.0 2.0 3.0 4.0 5.0 6.0 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CISOTX::Card4 card4( iss );

        REQUIRE( -10 == card4.kbr.value );
        REQUIRE( 1.0 * dimwits::gram == card4.amass.value );
        REQUIRE( Approx( 2.0 ) == card4.efiss.value );
        REQUIRE( Approx( 3.0 ) == card4.ecapt.value );
        REQUIRE( 4.0*dimwits::kelvin == card4.temp.value );
        REQUIRE( Approx( 5.0 ) == card4.sigpot.value );
        REQUIRE( Approx( 6.0 ) == card4.adens.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                         " -10 1.0 2.0 3.0 4.0 5.0 6.0 7 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card4( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
