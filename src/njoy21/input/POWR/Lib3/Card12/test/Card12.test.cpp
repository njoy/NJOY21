#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card12",
          "[POWR] [Lib3] [Card12]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::string inp(
 std::string( " 235.555 99.1 " ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 " ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 " ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 " ) +
 std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 " ) +
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 " ) +
 std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 " ) +
 std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 6.8 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR::Lib3::Card12 card12( iss, 69 );

        REQUIRE( Approx( 235.555 ) == card12.aw.value );
        REQUIRE( 99.1*dimwits::kelvin == card12.temp.value );

        for( int i = 0; i < 69; i++ ){
          double d( i*0.1 );
          REQUIRE( Approx( d ) == card12.fpa.value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      std::string inp(
 std::string( " 235.555 -99.1 " ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 " ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 " ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 " ) +
 std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 " ) +
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 " ) +
 std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 " ) +
 std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 6.8 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12( iss, 69 ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      std::string inp(
 std::string( " 235.555 99.1 " ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 " ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 " ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 " ) +
 std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 " ) +
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 " ) +
 std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 " ) +
 std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 6.8 6.9 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12( iss, 69 ) );
      }
    } // WHEN

    WHEN( "too few values are provided" ){
      std::string inp(
 std::string( " 235.555 99.1 " ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 " ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 " ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 " ) +
 std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 " ) +
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 " ) +
 std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 " ) +
 std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 6.8 6.9 /" ) );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card12( iss, 69 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
