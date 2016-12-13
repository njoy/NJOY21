#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card2 inputs",
          "[ACER], [Card2]" ){
  long ln{0};
  WHEN( "all optional values are are given" ){
    std::istringstream issCard2( "1 0 2 .80 4" );
    ACER::Card2 card2( issCard2, ln );

    THEN( "the card2 values can be verified" ){
      REQUIRE( 1 == card2.iopt.value );
      REQUIRE( 0 == card2.iprint.value );
      REQUIRE( 2 == card2.itype.value );
      REQUIRE( .80 == card2.suff.value );
      REQUIRE( 4 == card2.nxtra.value );
    }
  }
  WHEN( "none of the optional values are given" ){
    std::istringstream issCard2( "-2" );
    ACER::Card2 card2( issCard2, ln );

    THEN( "the card2 values can be verified" ){
      REQUIRE( -2 == card2.iopt.value );
      REQUIRE( 1 == card2.iprint.value );
      REQUIRE( 1 == card2.itype.value );
      REQUIRE( .00 == card2.suff.value );
      REQUIRE( 0 == card2.nxtra.value );
    }
  }

  GIVEN( "invalid Card2 input" ){
    WHEN( "input is empty, i.e., no iopt parameter" ){
      std::istringstream issCard2( "" );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card2(issCard2, ln ) );
      }
    }
    WHEN( "parameters are incorrect" ){
      std::istringstream issCard2( " 3 -1" );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card2(issCard2, ln ) );
      }
    }
  }
}

