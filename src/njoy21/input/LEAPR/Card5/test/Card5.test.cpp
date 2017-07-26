#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "nout input values",
  "[LEAPR], [Card5]" ){
  GIVEN( "valid card5 inputs" ){
    WHEN( "all card5 inputs provided" ){
      iRecordStream<char> is( std::istringstream( "0.99 20.44 2 1 1 1" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card5 card5( is );
        REQUIRE( card5.awr.value   == 0.99 );
        REQUIRE( card5.spr.value   == 20.44 * dimwits::barns );
        REQUIRE( card5.npr.value   == 2    );
        REQUIRE( card5.iel.value   == 1    );
        REQUIRE( card5.ncold.value == 1    );
        REQUIRE( card5.nsk.value   == 1    );
      } // THEN
    } // WHEN
    WHEN( "optional card5 inputs not provided" ){
      iRecordStream<char> is( std::istringstream( "0.99 20.44 2 /" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card5 card5( is );
        REQUIRE( card5.iel.value   == 0 );
        REQUIRE( card5.ncold.value == 0 );
        REQUIRE( card5.nsk.value   == 0 );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid card5 inputs" ){
    WHEN( "card5 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( "0.0 20.4 2 1 1 1" ) );
      iRecordStream<char> is2( std::istringstream( "0.9 0.00 2 1 1 1" ) );
      iRecordStream<char> is3( std::istringstream( "0.9 20.4 0 1 1 1" ) );
      iRecordStream<char> is4( std::istringstream( "0.9 20.4 2 7 1 1" ) );
      iRecordStream<char> is5( std::istringstream( "0.9 20.4 2 1 5 1" ) );
      iRecordStream<char> is6( std::istringstream( "0.9 20.4 2 1 1 3" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card5( is1 ) );
        REQUIRE_THROWS( LEAPR::Card5( is2 ) );
        REQUIRE_THROWS( LEAPR::Card5( is3 ) );
        REQUIRE_THROWS( LEAPR::Card5( is4 ) );
        REQUIRE_THROWS( LEAPR::Card5( is5 ) );
        REQUIRE_THROWS( LEAPR::Card5( is6 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

