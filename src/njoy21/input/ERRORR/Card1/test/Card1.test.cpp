#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1",
          "[ERRORR] [Card1]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid input is provided" ){
      std::string inp( " 48 50 52 54 56 58 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        ERRORR::Card1 card1( iss );

        REQUIRE( 48 == card1.nendf.value );
        REQUIRE( 50 == std::get<0>( *( card1.rest ) ).value );
        REQUIRE( 52 == std::get<1>( *( card1.rest ) ).value );
        REQUIRE( 54 == std::get<2>( *( card1.rest ) ).value );
        REQUIRE( 56 == std::get<3>( *( card1.rest ) ).value );
        REQUIRE( 58 == std::get<4>( *( card1.rest ) ).value );
      }
    } // WHEN

    WHEN( "all defaults are used" ){
      std::string inp( " 20 21 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the default values can be verified" ){
        ERRORR::Card1 card1( iss );

        REQUIRE( 20 == card1.nendf.value );
        REQUIRE( 21 == std::get<0>( *( card1.rest ) ).value );
        REQUIRE( 0 == std::get<1>( *( card1.rest ) ).value );
        REQUIRE( 0 == std::get<2>( *( card1.rest ) ).value );
        REQUIRE( 0 == std::get<3>( *( card1.rest ) ).value );
        REQUIRE( 0 == std::get<4>( *( card1.rest ) ).value );
      }
    } // WHEN

    WHEN( "the dummy mt33 file path is used" ){
      iRecordStream<char> iss( std::istringstream( " 999 /" ) );

      THEN( "the value can be verified and the rest are null" ){
        ERRORR::Card1 card1( iss );

        REQUIRE( 999 == card1.nendf.value );
        REQUIRE( std::nullopt == card1.rest );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided on dummy path" ){
      iRecordStream<char> iss( std::istringstream( " 999 22 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided on normal path" ){
      std::string inp( " 20 21 22 23 24 25 26 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too few values are provided on normal path" ){
      iRecordStream<char> iss( std::istringstream( " 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided on the normal path" ){
      iRecordStream<char> iss( std::istringstream( " 20 21 19 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Card1( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
