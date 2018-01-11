#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card6",
          "[POWR] [Lib1] [Card6]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12.0 13.0 14.0 /" ) );

      POWR::Lib1::Card6 card6( iss );

      THEN( "the value can be verified" ){
        auto abs = card6.abs.value;

        REQUIRE( 69 == abs.size() );

        REQUIRE( Approx( 12.0 ) == abs.at(0) );
        REQUIRE( Approx( 13.0 ) == abs.at(1) );
        REQUIRE( Approx( 14.0 ) == abs.at(2) );

        for( size_t i = 3; i < abs.size(); i++ ){
          REQUIRE( Approx( 0.0 ) == abs.at(i) );
        }
      } // THEN
    } // GIVEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
" 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0 11.0 12.0 13.0 14.0 15.0 16.0 17.0 18.0 19.0 20.0 21.0 22.0 23.0 24.0 25.0 26.0 27.0 28.0 29.0 30.0 31.0 32.0 33.0 34.0 35.0 36.0 37.0 38.0 39.0 40.0 41.0 42.0 43.0 44.0 45.0 46.0 47.0 48.0 49.0 50.0 51.0 52.0 53.0 54.0 55.0 56.0 57.0 58.0 59.0 60.0 61.0 62.0 63.0 64.0 65.0 66.0 67.0 68.0 69.0 70.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card6( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
