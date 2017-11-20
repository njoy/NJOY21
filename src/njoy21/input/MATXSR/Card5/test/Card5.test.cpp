#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card5",
          "[MATXSR], [Card5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string i : { "", "12345", "12345678" } ){
        iRecordStream<char> iss( std::istringstream( "'" + i + "' /" ) );

        MATXSR::Card5 card5( iss );
        THEN( "the value can be verified" ){
          REQUIRE( i == card5.hpart.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( "'123456789' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card5( iss ) );
      }
    }

    WHEN( "too many inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "'12345678' 9 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card5( iss ) );
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card5( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
