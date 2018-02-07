#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card11a",
          "[POWR] [Lib3] [Card11a]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::string inp(
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9" ) +
 std::string( " 1.0 1.1 1.2 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR::Lib3::Card11a card11a( iss, 13 );

        for( int i = 0; i < 13; i++ ){
          double d( i*0.1 );

          REQUIRE( Approx( d ) == card11a.tot.value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are given" ){
      std::string inp(
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9" ) +
 std::string( " 1.0 1.1 1.2 1.3 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card11a( iss, 13 ) );
      }
    } // WHEN

    WHEN( "too few values are given" ){
      std::string inp(
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9" ) +
 std::string( " 1.0 1.1 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card11a( iss, 13 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
