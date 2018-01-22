#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card5",
          "[POWR] [Lib1] [Card5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " '1234567'/" ) );

      POWR::Lib1::Card5 card5( iss );

      THEN( "the value can be verified" ){
        REQUIRE( "1234567" == card5.fsn.value );
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      POWR::Lib1::Card5 card5( iss );

      THEN( "the default can be verified" ){
        REQUIRE( "" == card5.fsn.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream(
                             "'12345678901234567890123456789012345678901'/" ) );

      THEN( "an argument is thrown" ){
        REQUIRE_THROWS( POWR::Lib1::Card5( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
