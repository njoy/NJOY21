#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2a",
          "[WIMSR] [Card2a]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 10 12 8 /" ) );

      WIMSR::Card2a card2a( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 20 == card2a.ngnd.value );
        REQUIRE( 10 == card2a.nfg.value );
        REQUIRE( 12 == card2a.nrg.value );
        REQUIRE( 8 == card2a.igref.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid set of values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 10 12 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card2a( iss ) );
      }
    }

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 10 12 8 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card2a( iss ) );
      }
    }

    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card2a( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
