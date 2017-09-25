#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card5 inputs",
          "[PLOTR], [Card5]" ){

  GIVEN( "valid PLOTR Card5 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard5(
            std::istringstream(" 10.0 50.0 2 / " ) );
      PLOTR::Card5 card5(issCard5);

      THEN( "the members can be tested" ){
        REQUIRE( 10.0f == card5.el.value );
        REQUIRE( 50.0f == card5.eh.value );
        REQUIRE( 2.0f == card5.xstep.value );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      iRecordStream<char> issCard5( std::istringstream(" 500.0 400000.0 / " ) );
      PLOTR::Card5 card5(issCard5);

      THEN( "the members can be tested" ){
        REQUIRE( 500.0f == card5.el.value );
        REQUIRE( 400000.0f == card5.eh.value );
        REQUIRE( 1.0f == card5.xstep.value );
      }
    } //WHEN
    WHEN( "No values are given" ){
      iRecordStream<char> issCard5( std::istringstream(" / "));
      PLOTR::Card5 card5(issCard5);

      THEN( "the members can be tested" ){
        REQUIRE( 0.0f == card5.el.value );
        REQUIRE( 1.0f == card5.eh.value );
        REQUIRE( 1.0f == card5.xstep.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard5( std::istringstream(
             "-1.0 1.0 0.5/" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card5(issCard5) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard5( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card5(issCard5) );
        }
      }{
        iRecordStream<char> issCard5( std::istringstream(
              "1.0 4.0 -0.6/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card5(issCard5) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard5( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card5(issCard5) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
