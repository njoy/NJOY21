#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2",
          "[WIMSR] [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "1 5 9 /" ) );

      WIMSR::Card2 card2( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 1 == card2.iprint.value );
        REQUIRE( 5 == card2.iverw.value );
        REQUIRE( 9 == card2.igroup.value );
      }
    }

    WHEN( "one value is provided" ){
      iRecordStream<char> iss( std::istringstream( "1 /" ) );

      WIMSR::Card2 card2( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 1 == card2.iprint.value );
        REQUIRE( 4 == card2.iverw.value );
        REQUIRE( 0 == card2.igroup.value );
      }
    }

    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      WIMSR::Card2 card2( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 0 == card2.iprint.value );
        REQUIRE( 4 == card2.iverw.value );
        REQUIRE( 0 == card2.igroup.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( "1 5 9 10 /" ) );

      REQUIRE_THROWS( WIMSR::Card2( iss ) );
    }

    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( "1 5 10 /" ) );

      REQUIRE_THROWS( WIMSR::Card2( iss ) );
    }
  } // GIVEN
} // SCENARIO
