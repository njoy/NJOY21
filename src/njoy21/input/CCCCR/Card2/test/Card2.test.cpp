#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card2",
          "[CCCCR] [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all inputs are specified" ){
      iRecordStream<char> iss( std::istringstream( " 0 5 '1234567' /" ) );

      THEN( "the values can be verified" ){
        CCCCR::Card2 card2( iss );

        REQUIRE( 0 == card2.lprint.value );
        REQUIRE( 5 == card2.ivers.value );
        REQUIRE( "1234567" == card2.huse.value );
      }
    } // WHEN

    WHEN( "all the defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " 1 /" ) );

      THEN( "the default values can be verified" ){
        CCCCR::Card2 card2( iss );

        REQUIRE( 1 == card2.lprint.value );
        REQUIRE( 0 == card2.ivers.value );
        REQUIRE( "" == card2.huse.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card2( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 5 '12345678901' 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card2( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 5 '123456789012' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::Card2( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
