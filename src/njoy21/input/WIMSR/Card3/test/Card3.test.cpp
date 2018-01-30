#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card3",
          "[WIMSR] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "all valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9238 10 9238. 1 /" ) );

      WIMSR::Card3 card3( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 9238 == card3.mat.value );
        REQUIRE( 10 == card3.nfid.value );
        REQUIRE( Approx( 9238.0 ) == card3.rdfid.value );
        REQUIRE( 1 == card3.iburn.value );
      }
    }

    WHEN( "the final value is left to the default" ){
      iRecordStream<char> iss( std::istringstream( " 9238 10 9238. /" ) );

      WIMSR::Card3 card3( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 9238 == card3.mat.value );
        REQUIRE( 10 == card3.nfid.value );
        REQUIRE( Approx( 9238.0 ) == card3.rdfid.value );
        REQUIRE( 0 == card3.iburn.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9238 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card3( iss ) );
      }
    }

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9238 10 9238. 1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card3( iss ) );
      }
    }

    WHEN( "one value is invalid" ){
      iRecordStream<char> iss( std::istringstream( " 9238 10 -12. 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card3( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
