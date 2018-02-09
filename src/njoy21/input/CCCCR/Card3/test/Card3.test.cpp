#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card3",
          "[CCCCR] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( "'1234567890'/" ) );

      THEN( "the value can be verified" ){
        CCCCR::Card3 card3( iss );

        REQUIRE( "1234567890" == card3.hsetid.value );
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        CCCCR::Card3 card3( iss );

        REQUIRE( "" == card3.hsetid.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid inputs is provided" ){
      iRecordStream<char> iss( std::istringstream( "'1234567890123' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an extra value is provided" ){
      iRecordStream<char> iss( std::istringstream( "'1234567890' 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
