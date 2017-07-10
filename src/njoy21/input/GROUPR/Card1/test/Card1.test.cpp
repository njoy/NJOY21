#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
          "[GROUPR], [Card1]" ){

  GIVEN( "valid GROUPR Card1 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard1( std::istringstream("20 21 22 23 / " ) );
      GROUPR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 20 == card1.nendf.value );
        REQUIRE( 21 == card1.npend.value );
        REQUIRE( 22 == card1.ngout1.value );
        REQUIRE( 23 == card1.ngout2.value );
      }
    }
    WHEN( "All values are given" ){
      iRecordStream<char> issCard1( std::istringstream("20 21 0 23 / " ) );
      GROUPR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 20 == card1.nendf.value );
        REQUIRE( 21 == card1.npend.value );
        REQUIRE( 0 == card1.ngout1.value );
        REQUIRE( 23 == card1.ngout2.value );
      }
    }
  }

  GIVEN( "invalid inputs" ){
    iRecordStream<char> issCard1( std::istringstream("20 20 22 23 /" ) );
    
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card1(issCard1) );
    }
  }
}
