#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR, Card2",
          "[MIXR] [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a simple, valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 8 12 /" ) );

      THEN( "the values can be verified" ){
        MIXR::Card2 card2( iss );

        REQUIRE( 1 == card2.mtnList.at( 0 ).value );
        REQUIRE( 8 == card2.mtnList.at( 1 ).value );
        REQUIRE( 12 == card2.mtnList.at( 2 ).value );
      }
    } // WHEN

    WHEN( "the maximum number of mt numbers are provided" ){
      iRecordStream<char> iss( std::istringstream(
                    " 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 /" ) );

      THEN( "the values can be verified" ){
        MIXR::Card2 card2( iss );

        for( int i = 0; i < 20; i++ ){
          REQUIRE( ( i + 1 ) == card2.mtnList.at( i ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card2( iss ) );
      }
    } // WHEN

    WHEN( "too many mt numbers are provided" ){
      iRecordStream<char> iss( std::istringstream(
                 " 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card2( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream(
                     " 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card2( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
