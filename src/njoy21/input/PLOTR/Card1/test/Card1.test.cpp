#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card1 inputs",
          "[PLOTR], [Card1]" ){

  GIVEN( "valid PLOTR Card1 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard1( std::istringstream("0 2 -0.2 3 / " ) );
      PLOTR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 0 == card1.lori.value );
        REQUIRE( 2 == card1.istyle.value );
        REQUIRE( Approx(-0.2) == card1.size.value );
        REQUIRE( 3 == card1.ipcol.value );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      iRecordStream<char> issCard1( std::istringstream("1 2 / " ) );
      PLOTR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 1 == card1.lori.value );
        REQUIRE( 2 == card1.istyle.value );
        REQUIRE( Approx(0.30) == card1.size.value );
        REQUIRE( 0 == card1.ipcol.value );
      }
    } //WHEN
    WHEN( "No values are given" ){
      iRecordStream<char> issCard1( std::istringstream(" / "));
      PLOTR::Card1 card1(issCard1);

      THEN( "the members can be tested" ){
        REQUIRE( 1 == card1.lori.value );
        REQUIRE( 2 == card1.istyle.value );
        REQUIRE( Approx(0.30) == card1.size.value );
        REQUIRE( 0 == card1.ipcol.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard1( std::istringstream("20 20 22 23 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card1(issCard1) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard1( std::istringstream("0 2 -22 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card1(issCard1) );
        }
      }{
        iRecordStream<char> issCard1( std::istringstream("2 1 0.2 4 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card1(issCard1) );
        }
      }{
        iRecordStream<char> issCard1( std::istringstream("0 -2 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card1(issCard1) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard1( std::istringstream("0 1 0.6 6 99 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card1(issCard1) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
