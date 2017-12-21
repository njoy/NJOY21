#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card2",
          "[MATXSR], [Card2]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 3 'testing 123' /" ) );

      MATXSR::Card2 card2( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 3 == card2.ivers.value );
        REQUIRE( "testing 123" == card2.huse.value );
      }
    }

    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      MATXSR::Card2 card2( iss );
      THEN( "the default values are returned" ){
        REQUIRE( 0 == card2.ivers.value );
        REQUIRE( "" == card2.huse.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 'testing 123' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card2( iss ) );
      }
    }

    WHEN( "an invalid huse is provided" ){
      iRecordStream<char> iss( std::istringstream( " 3 '12345678901234567' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card2( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
