#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card6",
          "[POWR] [Lib1] [Card6]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::string inp(
  std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 " ) +
  std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 " ) +
  std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 " ) +
  std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 " ) +
  std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 " ) +
  std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 " ) +
  std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 6.8 /" ) );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      POWR::Lib1::Card6 card6( iss );

      THEN( "the value can be verified" ){
        for( size_t i = 0; i < 69; i++ ){
          double d( i*0.1 );
          REQUIRE( Approx( d ) == card6.abs.value.at(i) );
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
