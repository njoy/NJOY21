#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card4",
          "[MATXSR], [Card4]" ){

  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string i : { "", "1234567890",
"123456789012345678901234567890123456789012345678901234567890123456789012" } ){
        iRecordStream<char> iss( std::istringstream( "'" + i + "' /") );

        MATXSR::Card4 card4( iss );
        THEN( "the value can be verified" ){
          REQUIRE( i == card4.hsetid.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an extra value is given" ){
      iRecordStream<char> iss( std::istringstream( " '123456789' 10 / " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card4( iss ) );
      }
    }

    WHEN( "the provided value is too long" ){
      iRecordStream<char> iss( std::istringstream(
"'1234567890123456789012345678901234567890123456789012345678901234567890123' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card4( iss ) );
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card4( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
