#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card12c",
          "[POWR] [Lib3] [Card12c]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 0.3 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card12c card12c( iss, 4 );

        for( int i = 0; i < 4; i++ ){
          double d( i*0.1 );
          REQUIRE( Approx( d ) == card12c.scat.value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12c( iss, 4 ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 0.3 0.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12c( iss, 4 ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 -0.2 0.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12c( iss, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
