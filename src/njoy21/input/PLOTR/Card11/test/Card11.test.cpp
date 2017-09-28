#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card11 inputs",
          "[PLOTR], [Card11]" ){

  GIVEN( "valid PLOTR Card11 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard11(
            std::istringstream(" 10.0 50.0 2.0 -3.0 -2.0 -0.5 / " ) );
      PLOTR::Card11 card11(issCard11);

      THEN( "the members can be tested" ){
        REQUIRE( 10.0f == card11.xv.value );
        REQUIRE( 50.0f == card11.yv.value );
        REQUIRE( 2.0f == card11.zv.value );
        REQUIRE( -3.0f == card11.x3.value );
        REQUIRE( -2.0f == card11.y3.value );
        REQUIRE( -0.5f == card11.z3.value );
      }
    } //WHEN
    WHEN( "All zeros" ){
      iRecordStream<char> issCard11( std::istringstream(
                           " 0.0 0.0 0.0 0.0 0.0 0.0 / " ) );
      PLOTR::Card11 card11(issCard11);

      THEN( "the members can be tested" ){
        REQUIRE( 0.0f == card11.xv.value );
        REQUIRE( 0.0f == card11.yv.value );
        REQUIRE( 0.0f == card11.zv.value );
        REQUIRE( 0.0f == card11.x3.value );
        REQUIRE( 0.0f == card11.y3.value );
        REQUIRE( 0.0f == card11.z3.value );
      }
    } //WHEN
    WHEN( "No values" ){
      iRecordStream<char> issCard11( std::istringstream( " /" ) );
      PLOTR::Card11 card11(issCard11);

      THEN( "the default values are returned" ){
        REQUIRE( 15.0f == card11.xv.value );
        REQUIRE( -15.0f == card11.yv.value );
        REQUIRE( 15.0f == card11.zv.value );
        REQUIRE( 2.5f == card11.x3.value );
        REQUIRE( 6.5f == card11.y3.value );
        REQUIRE( 2.5f == card11.z3.value );
      }
    }
  } // GIVEN
}//SCENARIO
