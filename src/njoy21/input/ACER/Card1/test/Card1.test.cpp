#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
          "[ACER], [Card1]" ){

  GIVEN( "valid ACE Card1 inputs" ){
    iRecordStream<char> issCard1( std::istringstream("20 21 22 23 24" ) );
    ACER::Card1 card1(issCard1);

    THEN( "the members can be tested" ){
      REQUIRE( 20 == card1.nendf.value );
      REQUIRE( 21 == card1.npend.value );
      REQUIRE( 22 == card1.ngend.value );
      REQUIRE( 23 == card1.nace.value );
      REQUIRE( 24 == card1.ndir.value );
    }

    iRecordStream<char> issCard2( std::istringstream("20 21 22 0 24" ) );
    card1 = ACER::Card1(issCard2);
    THEN( "the members can be tested" ){
      REQUIRE( 0 == card1.nace.value );
    }

  }

  GIVEN( "invalid inputs" ){
    iRecordStream<char> issCard1( std::istringstream("20 20 22 23 24" ) );
    
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( ACER::Card1(issCard1) );
    }
  }
}
