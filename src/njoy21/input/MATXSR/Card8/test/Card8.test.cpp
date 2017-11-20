#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card8",
          "[MATXSR], [Card8]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : { 0, 1, 10, 100 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) + " /" ) );

        MATXSR::Card8 card8( iss );
        THEN( "the value can be verified" ){
          REQUIRE( i == card8.jinp.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card8( iss ) );
      }
    }

    WHEN( "too many values are given" ){
      iRecordStream<char> iss( std::istringstream( " 1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card8( iss ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card8( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
