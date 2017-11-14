#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card2 inputs",
          "[RESXSR], [Card2]" ){

  GIVEN( "valid inputs" ){

    iRecordStream<char> issCard2( std::istringstream(
                                  "2 3 4 0.1 100.1 10.6 /" ) );

    RESXSR::Card2 card2( issCard2 );

    THEN( "the values can be verified" ){
      REQUIRE( 2 == card2.nmat.value );
      REQUIRE( 3 == card2.maxt.value );
      REQUIRE( 4 == card2.nholl.value );
      REQUIRE( Approx( 0.1 ) == card2.efirst.value );
      REQUIRE( Approx( 100.1 ) == card2.elast.value );
      REQUIRE( Approx( 10.6 ) == card2.eps.value );
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){

    WHEN( "elast less than efirst" ){
      iRecordStream<char> issCard2( std::istringstream(
                                    "2 3 4 10.1 10.0 0.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card2( issCard2 ) );
      }
    }

    WHEN( "a negative energy value is given" ){
      iRecordStream<char> issCard2( std::istringstream(
                                    "2 3 4 -0.1 10.0 0.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card2( issCard2 ) );
      }
    }

    WHEN( "fewer values than required are given" ){
      iRecordStream<char> issCard2( std::istringstream(
                                    "2 3 4 0.1 100.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card2( issCard2 ) );
      }
    }

    WHEN( "too many values are given" ){
      iRecordStream<char> issCard2( std::istringstream(
                                    "2 3 4 0.1 100.1 10.6 11 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card2( issCard2 ) );
      }
    }
  } // GIVEN
} // SCENARIO
