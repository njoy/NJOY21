#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card5 inputs",
          "[PLOTR], [Card5]" ){

  Argument< PLOTR::Card4::Xtag > xtag;
  Argument< PLOTR::Card4::Itype > itype; itype.value = 1;

  GIVEN( "valid PLOTR Card5 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard5(
            std::istringstream(" 10.0 50.0 2 / " ) );
      PLOTR::Card5 card5( issCard5, xtag, itype );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 10.0 ) == card5.el.value );
        REQUIRE( Approx( 50.0 ) == card5.eh.value );
        REQUIRE( Approx( 2.0 ) == card5.xstep.value );
        REQUIRE( Approx( 10.0 ) == *(xtag.value) );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      iRecordStream<char> issCard5( std::istringstream(" 500.0 400000.0 / " ) );
      PLOTR::Card5 card5( issCard5, xtag, itype );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 500.0 ) == card5.el.value );
        REQUIRE( Approx( 400000.0 ) == card5.eh.value );
        REQUIRE( Approx( 1.0 ) == card5.xstep.value );
        REQUIRE( Approx( 500.0 ) == *(xtag.value) );
      }
    } //WHEN
    WHEN( "No values are given" ){
      iRecordStream<char> issCard5( std::istringstream(" / "));
      PLOTR::Card5 card5( issCard5, xtag, itype );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 0.0 ) == card5.el.value );
        REQUIRE( Approx( 0.0 ) == card5.eh.value );
        REQUIRE( Approx( 1.0 ) == card5.xstep.value );
        REQUIRE( Approx( 0.0 ) == *(xtag.value) );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard5( std::istringstream(
             "-1.0 1.0 0.5/" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard5( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype) );
        }
      }{
        iRecordStream<char> issCard5( std::istringstream(
              "1.0 4.0 -0.6/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard5( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
