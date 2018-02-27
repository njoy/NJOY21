#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card3",
          "[ERRORR] [Normal] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 314.15 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card3 card3( iss );

        REQUIRE( 1 == card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == card3.tempin.value );
      }
    } // WHEN

    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default values can be verified" ){
        ERRORR::Normal::Card3 card3( iss );

        REQUIRE( 0 == card3.mprint.value );
        REQUIRE( 300.0*dimwits::kelvin == card3.tempin.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 314.1 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 314.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
