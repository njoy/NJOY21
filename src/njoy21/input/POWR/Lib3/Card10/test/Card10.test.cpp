#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card10",
          "[POWR] [Lib3] [Card10]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card10 card10( iss, 13 );

        for( int i = 0; i < 13; i++ ){
          double d{ i*0.1 + 0.1};
          REQUIRE( Approx( d ) == card10.lambda.value.at(i) );
        }
      }
    } // WHEN

    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream(
           " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 1.5 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card10 card10( iss, 15 );

        for( int i = 0; i < 15; i++ ){
          double d{ i*0.1 + 0.1};
          REQUIRE( Approx( d ) == card10.lambda.value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are given for 13 resonance groups" ){
      iRecordStream<char> iss( std::istringstream(
               " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card10( iss, 13 ) );
      }
    } // WHEN

    WHEN( "too many values are given for 15 resonance groups" ){
      iRecordStream<char> iss( std::istringstream(
       " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 1.5 1.6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card10( iss, 15 ) );
      }
    } // WHEN

    WHEN( "too few values are given for 15 resonance groups" ){
      iRecordStream<char> iss( std::istringstream(
               " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card10( iss, 15 ) );
      }
    } // WHEN

    WHEN( "too few values are given for 13 resonance groups" ){
      iRecordStream<char> iss( std::istringstream(
                       " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card10( iss, 13 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
