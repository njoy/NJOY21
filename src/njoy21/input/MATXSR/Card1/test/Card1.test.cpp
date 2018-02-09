#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card1 input",
          "[MATXSR],[Card1]" ){

  const int ngen1 = 24;
  const int ngen2 = 25;
  const int nmatx = 26;
  const int ngen3 = 27;
  const int ngen4 = 28;
  const int ngen5 = 29;
  const int ngen6 = 30;
  const int ngen7 = 31;

  GIVEN( "valid inputs" ){
    WHEN( "all inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 24 25 26 27 28 29 30 31 /" ) );

      MATXSR::Card1 card1( iss );
      THEN( "the values can be verified" ){

        REQUIRE( ngen1 == card1.ngen1.value );
        REQUIRE( ngen2 == card1.ngen2.value );
        REQUIRE( nmatx == card1.nmatx.value );
        REQUIRE( ngen3 == card1.ngen3.value );
        REQUIRE( ngen4 == card1.ngen4.value );
        REQUIRE( ngen5 == card1.ngen5.value );
        REQUIRE( ngen6 == card1.ngen6.value );
        REQUIRE( ngen7 == card1.ngen7.value );
      }
    }

    WHEN( "all defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 24 25 26 /" ) );

      MATXSR::Card1 card1( iss );
      THEN( "the default value is returned" ){

        REQUIRE( ngen1 == card1.ngen1.value );
        REQUIRE( ngen2 == card1.ngen2.value );
        REQUIRE( nmatx == card1.nmatx.value );
        REQUIRE( 0 == card1.ngen3.value );
        REQUIRE( 0 == card1.ngen4.value );
        REQUIRE( 0 == card1.ngen5.value );
        REQUIRE( 0 == card1.ngen6.value );
        REQUIRE( 0 == card1.ngen7.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 24 24 26 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card1( iss ) );
      }
    }

    WHEN( "one of the required values is not provided" ){
      iRecordStream<char> iss( std::istringstream( " 24 25 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card1( iss ) );
      }
    }

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                               " 24 25 26 27 28 29 30 31 32 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card1( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
