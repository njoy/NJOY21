#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card1",
          "[CCCCR] [CISOTX] [Card1]" ){
  const int ngroup = 12;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 0 10 0 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CISOTX::Card1 card1( iss, ngroup );

        REQUIRE( 12 == card1.nsblok.value );
        REQUIRE( 0 == card1.maxup.value );
        REQUIRE( 10 == card1.maxdn.value );
        REQUIRE( 0 == card1.ichix.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 0 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card1( iss, ngroup ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 0 10 0 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card1( iss, ngroup ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 1 10 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card1( iss, ngroup ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
