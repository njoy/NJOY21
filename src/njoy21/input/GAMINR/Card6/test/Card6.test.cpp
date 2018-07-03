#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card6 inputs", "[GAMINR], [Card6]" ){
  GIVEN( "all values are given" ){
    iRecordStream<char> issCard6( std::istringstream( "3 18 'MF3 MT18' /" ) );

    GAMINR::Card6 card6( issCard6 );

    THEN( "the card6 values can be verified" ){
      REQUIRE( 3 == card6.mfd.value );
      REQUIRE( 18 == card6.rest->first.value );
      REQUIRE( "MF3 MT18" == card6.rest->second.value );
    }
  }
  GIVEN( "mfd=0" ){
    iRecordStream<char> issCard6( std::istringstream( "0 /" ) );

    GAMINR::Card6 card6( issCard6 );

    THEN( "the card6 values can be verified" ){
      REQUIRE( 0 == card6.mfd.value );
      REQUIRE( 0 == card6.rest->first.value );
      REQUIRE( "" == card6.rest->second.value );
    }
  }
  GIVEN( "mfd=-1" ){
    iRecordStream<char> issCard6( std::istringstream( "-1 /" ) );

    GAMINR::Card6 card6( issCard6 );

    THEN( "the card6 values can be verified" ){
      REQUIRE( -1 == card6.mfd.value );
      REQUIRE( std::nullopt == card6.rest );
    }
  }

  GIVEN( "mfd is invalid" ){
    WHEN( "mfd=-2" ){
      iRecordStream<char> issCard6( std::istringstream( "-2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card6( issCard6 ) );
      }
    }
    WHEN( "mfd=1000001" ){
      iRecordStream<char> issCard6( std::istringstream( "1000001 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card6( issCard6 ) );
      }
    }
  }
} // SCENARIO

