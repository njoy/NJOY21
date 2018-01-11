#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card4",
          "[POWR] [Lib1] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " *123456*/" ) );

      POWR::Lib1::Card4 card4( iss );
      THEN( "the value can be verified" ){
        REQUIRE( "123456" == card4.word.value );
      } // THEN
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      POWR::Lib1::Card4 card4( iss );
      THEN( "the default value can be verified" ){
        REQUIRE( "" == card4.word.value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " *12345678901234567*/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card4( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
