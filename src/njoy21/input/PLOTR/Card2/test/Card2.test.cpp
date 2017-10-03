#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card2 inputs",
          "[PLOTR], [Card2]" ){

  Argument< PLOTR::Card1::Lori > lori;

  GIVEN( "valid PLOTR Card2 inputs" ){
    WHEN( "All values are given" ){
      lori.value = 1;
      iRecordStream<char> issCard2(
            std::istringstream("1 4 0.2 3.1 -0.1 -0.3 1.8 2.9 3.0 / " ) );
      PLOTR::Card2 card2(issCard2, lori);

      THEN( "the members can be tested" ){
        REQUIRE( 1 == card2.iplot.value );
        REQUIRE( 4 == card2.iwcol.value );
        REQUIRE( APPROX( 0.2 ) == card2.factx.value );
        REQUIRE( APPROX( 3.1 ) == card2.facty.value );
        REQUIRE( APPROX( -0.1 ) == card2.xll.value );
        REQUIRE( APPROX( -0.3 ) == card2.yll.value );
        REQUIRE( APPROX( 1.8 ) == card2.ww.value );
        REQUIRE( APPROX( 2.9 ) == card2.wh.value );
        REQUIRE( APPROX( 3.0 ) == card2.wr.value );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      lori.value = 0;
      iRecordStream<char> issCard2( std::istringstream("-1 2 2.2 1.3 1.5 0.2 / " ) );
      PLOTR::Card2 card2(issCard2, lori);

      THEN( "the members can be tested" ){
        REQUIRE( -1 == card2.iplot.value );
        REQUIRE( 2 == card2.iwcol.value );
        REQUIRE( APPROX( 2.2 ) == card2.factx.value );
        REQUIRE( APPROX( 1.3 ) == card2.facty.value );
        REQUIRE( APPROX( 1.5 ) == card2.xll.value );
        REQUIRE( APPROX( 0.2 ) == card2.yll.value );
        REQUIRE( APPROX( 7.5 ) == card2.ww.value );
        REQUIRE( APPROX( 10.0 ) == card2.wh.value );
        REQUIRE( APPROX( 0.0 ) == card2.wr.value );
      }
    } //WHEN
    WHEN( "No values are given" ){
      lori.value = 1;
      iRecordStream<char> issCard2( std::istringstream(" / "));
      PLOTR::Card2 card2(issCard2, lori);

      THEN( "the members can be tested" ){
        REQUIRE( 1 == card2.iplot.value );
        REQUIRE( 0 == card2.iwcol.value );
        REQUIRE( APPROX( 1.0 ) == card2.factx.value );
        REQUIRE( APPROX( 1.0 ) == card2.facty.value );
        REQUIRE( APPROX( 0.0 ) == card2.xll.value );
        REQUIRE( APPROX( 0.0 ) == card2.yll.value );
        REQUIRE( APPROX( 10.0 ) == card2.ww.value );
        REQUIRE( APPROX( 7.5 ) == card2.wh.value );
        REQUIRE( APPROX( 0.0 ) == card2.wr.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard2( std::istringstream(
             "101 9 -1.0 0.0 -0.6 10.6 -92.0 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card2(issCard2, lori) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        lori.value = 0;
        iRecordStream<char> issCard2( std::istringstream(
              "-12 2 1.1 -0.2 -0.1 1.5 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card2(issCard2, lori) );
        }
      }{
        lori.value = 1;
        iRecordStream<char> issCard2( std::istringstream(
              "1 -1 0.2 4.0 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card2(issCard2, lori) );
        }
      }{
        lori.value = 0;
        iRecordStream<char> issCard2( std::istringstream("200 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card2(issCard2, lori) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      lori.value = 0;
      iRecordStream<char> issCard2( std::istringstream(
            "-1 1 1.4 1.4 2.8 3.2 2.9 2.9 180.0 22/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card2(issCard2, lori) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
