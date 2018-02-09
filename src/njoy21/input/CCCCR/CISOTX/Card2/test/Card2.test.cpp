#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card2",
          "[CCCCR] [CISOTX] [Card2]" ){
  const int ngroup = 5;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                              " 10.0 11.0 12.0 13.0 14.0 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CISOTX::Card2 card2( iss, ngroup );

        for( int i = 0; i < 5; i++ ){
          REQUIRE( Approx( 10.0+i ) == card2.spec.value.at( i ) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                         " 10.0 11.0 12.0 13.0 14.0 15.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card2( iss, ngroup ) );
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card2( iss, ngroup ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
