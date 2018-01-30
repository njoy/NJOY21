#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card5",
          "[CCCCR] [Card5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" {
      iRecordStream<char> iss( std::istringstream(
                         " 'test01' 'test02' 'test03' 'test04' 1234 12.3 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::Card5 card5( iss );

        REQUIRE( "test01" == card5.hisnm.value );
        REQUIRE( "test02" == card5.habsid.value );
        REQUIRE( "test03" == card5.hident.value );
        REQUIRE( "test04" == card5.hmat.value );
        REQUIRE( 1234 == card5.imat.value );
        REQUIRE( Approx( 12.3 ) == card5.xspo.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                              " 'test01' 'test02' 'test03' 'test04' 1234 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card5( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                       " 'test01' 'test02' 'test03' 'test04' 1234 12.3 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card5( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream(
                        " 'test01' 'test02' 'test007' 'test04' 1234 12.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card5( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
