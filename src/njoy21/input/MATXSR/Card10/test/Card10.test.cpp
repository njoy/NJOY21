#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card10",
          "[MATXSR], [Card10]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "'test' 180 181 /" ) );

      MATXSR::Card10 card10( iss );
      THEN( "the values can be verified" ){
        REQUIRE( "test" == card10.hmat.value );
        REQUIRE( 180 == card10.matno.value );
        REQUIRE( 181 == card10.matgg.value );
      }
    }

    WHEN( "the final value uses the default" ){
      iRecordStream<char> iss( std::istringstream( "'test' 1800 /" ) );

      MATXSR::Card10 card10( iss );
      THEN( "the values, including the default, can be verified" ){
        REQUIRE( "test" == card10.hmat.value );
        REQUIRE( 1800 == card10.matno.value );
        REQUIRE( 1800 == card10.matgg.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "one of the required inputs is not given" ){
      iRecordStream<char> iss( std::istringstream( "'test' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card10( iss ) );
      }
    }

    WHEN( "one of the values is invalid" ){
      iRecordStream<char> iss( std::istringstream( "'123456789' 180 181 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card10( iss ) );
      }
    }

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( "'test' 180 181 42 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card10( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
