#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
          "[GAMINR], [Card1]" ){

  GIVEN( "valid GAMINR Card1 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard1( std::istringstream("20 21 22 23 / " ) );
      GAMINR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 20 == card1.nendf.value );
        REQUIRE( 21 == card1.npend.value );
        REQUIRE( 22 == card1.ngam1.value );
        REQUIRE( 23 == card1.ngam2.value );
      }
    }
    WHEN( "All values are given" ){
      iRecordStream<char> issCard1( std::istringstream("20 21 0 23 / " ) );
      GAMINR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 20 == card1.nendf.value );
        REQUIRE( 21 == card1.npend.value );
        REQUIRE( 0 == card1.ngam1.value );
        REQUIRE( 23 == card1.ngam2.value );
      }
    }
    WHEN( "Some members are omitted" ){
      iRecordStream<char> issCard1( std::istringstream("20 22 / "));
      GAMINR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 20 == card1.nendf.value );
        REQUIRE( 22 == card1.npend.value );
        REQUIRE( 0  == card1.ngam1.value );
        REQUIRE( 0  == card1.ngam2.value );
      }
    }
  }

  GIVEN( "invalid inputs" ){
    WHEN( "Duplicate values" ){
      iRecordStream<char> issCard1( std::istringstream("20 20 22 23 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card1(issCard1) );
      }
    }
    WHEN( "Different signed values" ){
      iRecordStream<char> issCard1( std::istringstream("20 21 -22 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card1(issCard1) );
      }
    }
    WHEN( "Different signed values" ){
      iRecordStream<char> issCard1( std::istringstream("20 21 22 -24 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card1(issCard1) );
      }
    }
    WHEN( "Different signed values" ){
      iRecordStream<char> issCard1( std::istringstream("-20 21 22 -24 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card1(issCard1) );
      }
    }
  }
}
