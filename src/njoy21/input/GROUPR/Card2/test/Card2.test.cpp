#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card2 inputs", "[GROUPR], [Card2]" ){
  WHEN( "all optional values are are given" ){
    iRecordStream<char> issCard2( 
        std::istringstream( "9238 1 3 3 4 3 5 0 /" ) );
    GROUPR::Card2 card2( issCard2 );

    THEN( "the card2 values can be verified" ){
      REQUIRE( 9238 == card2.matb.value );
      REQUIRE( 1 == card2.ign.value );
      REQUIRE( 3 == card2.igg.value );
      REQUIRE( 3 == card2.iwt.value );
      REQUIRE( 4 == card2.lord.value );
      REQUIRE( 3 == card2.ntemp.value );
      REQUIRE( 5 == card2.nsigz.value );
      REQUIRE( 0 == card2.iprint.value );
    }
  }
  WHEN( "none of the optional values are given" ){
    iRecordStream<char> issCard2( std::istringstream( "9238 1 3 3 4 /" ) );
    GROUPR::Card2 card2( issCard2 );

    THEN( "the card2 values can be verified" ){
      REQUIRE( 9238 == card2.matb.value );
      REQUIRE( 1 == card2.ign.value );
      REQUIRE( 3 == card2.igg.value );
      REQUIRE( 3 == card2.iwt.value );
      REQUIRE( 4 == card2.lord.value );
      REQUIRE( 1 == card2.ntemp.value );
      REQUIRE( 1 == card2.nsigz.value );
      REQUIRE( 1 == card2.iprint.value );
    }
  }

  GIVEN( "invalid Card2 input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " 3 -1 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GROUPR::Card2(issCard2 ) );
      }
    }
  }
} // SCENARIO
