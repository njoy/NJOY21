#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card3",
          "[MATXSR], [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 3 10 20 30 /" ) );

      MATXSR::Card3 card3( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 3 == card3.npart.value );
        REQUIRE( 10 == card3.ntype.value );
        REQUIRE( 20 == card3.nholl.value );
        REQUIRE( 30 == card3.nmat.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are given" ){
      iRecordStream<char> iss( std::istringstream( " 3 10 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card3( iss ) );
      }
    }

    WHEN( "too many values are given" ){
      iRecordStream<char> iss( std::istringstream( " 3 10 20 30 40 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card3( iss ) );
      }
    }

    WHEN( "one of the values is invalid" ){
      iRecordStream<char> iss( std::istringstream( " 3 -1 20 30 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card3( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
