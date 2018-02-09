#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card1",
          "[CCCCR] [CBRKXS] [Card1]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 -13 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS::Card1 card1( iss );

        REQUIRE( 12 == card1.nti.value );
        REQUIRE( -13 == card1.nzi.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 12 -13 14 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card1( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
