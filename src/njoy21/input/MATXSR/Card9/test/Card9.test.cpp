#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card9",
          "[MATXSR], [Card9]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {0, 1, 10, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) + " /" ) );

        MATXSR::Card9 card9( iss );
        THEN( "the value can be verified" ){
          REQUIRE( i == card9.joutp.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card9( iss ) );
      }
    }

    WHEN( "too many values are given" ){
      iRecordStream<char> iss( std::istringstream( " 1 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card9( iss ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card9( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
