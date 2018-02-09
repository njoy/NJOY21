#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR, Card2z",
          "[COVR] [Card2z]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream(" 5 0.1 0.2 0.3 0.4 1.0 /") );

      THEN( "the values can be verified" ){
        COVR::Card2z card2z( iss );

        REQUIRE( 5 == card2z.nlev.value );

        REQUIRE( Approx( 0.1 ) == card2z.tlev.value.at( 0 ) );
        REQUIRE( Approx( 0.2 ) == card2z.tlev.value.at( 1 ) );
        REQUIRE( Approx( 0.3 ) == card2z.tlev.value.at( 2 ) );
        REQUIRE( Approx( 0.4 ) == card2z.tlev.value.at( 3 ) );
        REQUIRE( Approx( 1.0 ) == card2z.tlev.value.at( 4 ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 5 0.1 0.2 0.3 1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card2z( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 3 0.1 0.2 1.0 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card2z( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
