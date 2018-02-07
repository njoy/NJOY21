#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card5",
          "[WIMSR] [Card5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 89 12 /" ) );

      WIMSR::Card5 card5( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 89 == card5.ntis.value );
        REQUIRE( 12 == card5.efiss.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 89 0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card5( iss ) );
      }
    } // WHEN

    WHEN( "too few arguments are provided" ){
      iRecordStream<char> iss( std::istringstream( " 89 / " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card5( iss ) );
      }
    } // WHEN

    WHEN( "too many arguments are provided" ){
      iRecordStream<char> iss( std::istringstream( " 89 12 13 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card5( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
