#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card4 inputs",
          "[PLOTR], [Card4]" ){

  GIVEN( "valid PLOTR Card4 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard4(
            std::istringstream(" 1 1 1 1 1.0 1.0 / " ) );
      PLOTR::Card4 card4(issCard4);

      THEN( "the members can be tested" ){
        REQUIRE( 1 == card4.itype.value );
        REQUIRE( 1 == card4.jtype.value );
        REQUIRE( 1 == card4.igrid.value );
        REQUIRE( 1 == card4.ileg.value );
        REQUIRE( Approx( 1.0 ) == *(card4.xtag.value) );
        REQUIRE( Approx( 1.0 ) == *(card4.ytag.value) );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      iRecordStream<char> issCard4( std::istringstream("-1 2 0 2 / " ) );
      PLOTR::Card4 card4(issCard4);

      THEN( "the members can be tested" ){
        REQUIRE(-1 == card4.itype.value );
        REQUIRE( 2 == card4.jtype.value );
        REQUIRE( 0 == card4.igrid.value );
        REQUIRE( 2 == card4.ileg.value );
        REQUIRE( std::nullopt == card4.xtag.value );
        REQUIRE( std::nullopt == card4.ytag.value );
      }
    } //WHEN
    WHEN( "No values are given" ){
      iRecordStream<char> issCard4( std::istringstream(" / "));
      PLOTR::Card4 card4(issCard4);

      THEN( "the members can be tested" ){
        REQUIRE( 4 == card4.itype.value );
        REQUIRE( 0 == card4.jtype.value );
        REQUIRE( 2 == card4.igrid.value );
        REQUIRE( 0 == card4.ileg.value );
        REQUIRE( std::nullopt == card4.xtag.value );
        REQUIRE( std::nullopt == card4.ytag.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard4( std::istringstream(
             "101 9 -1 6 -0.6 -10.6 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card4(issCard4) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard4( std::istringstream(
              "-1 2 4 0 2.0 8.0 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card4(issCard4) );
        }
      }{
        iRecordStream<char> issCard4( std::istringstream(
              "-5 1 0 1 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card4(issCard4) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard4( std::istringstream(
            "-1 1 1 1 2.8 3.2 2.9 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card4(issCard4) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
