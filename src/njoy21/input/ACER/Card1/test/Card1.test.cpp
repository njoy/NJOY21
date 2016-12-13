#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
          "[ACER], [Card1]" ){
  long ln{0};

  GIVEN( "valid ACE Card1 inputs" ){
    std::istringstream issCard1( "20 21 22 23 24" );
    ACER::Card1 card1(issCard1, ln);

    THEN( "the members can be tested" ){
      REQUIRE( 20 == card1.nendf.value );
      REQUIRE( 21 == card1.npend.value );
      REQUIRE( 22 == card1.ngend.value );
      REQUIRE( 23 == card1.nace.value );
      REQUIRE( 24 == card1.ndir.value );
    }

    issCard1.str( "20 21 22 0 24" );
    card1 = ACER::Card1(issCard1, ln);
    THEN( "the members can be tested" ){
      REQUIRE( 23 == card1.nace.value );
    }

  }

  GIVEN( "invalid inputs" ){
    std::istringstream issCard1( "20 20 22 23 24" );
    
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( ACER::Card1 card1(issCard1, ln) );
    }
  }
}
