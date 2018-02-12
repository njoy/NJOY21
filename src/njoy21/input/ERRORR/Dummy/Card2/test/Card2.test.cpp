#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Dummy, Card2",
          "[ERRORR] [Dummy] [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 21 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Dummy::Card2 card2( iss );

        REQUIRE( 20 == card2.nin.value );
        REQUIRE( 21 == card2.nout.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy::Card2( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 21 22 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy::Card2( iss ) );
      }
    } // WHEN

    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 24 -24 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy::Card2( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
