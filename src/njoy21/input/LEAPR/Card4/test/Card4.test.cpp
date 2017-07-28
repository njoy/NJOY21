#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card4 input",
  "[LEAPR], [Card4]" ){
  GIVEN( "valid card4 inputs" ){
    WHEN( "all card4 inputs provided" ){
      iRecordStream<char> is( std::istringstream( "1 1001 1 1" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card4 card4( is );
        REQUIRE( card4.mat.value   == 1    );
        REQUIRE( card4.za.value    == 1001 );
        REQUIRE( card4.isabt.value == 1    );
        REQUIRE( card4.ilog.value  == 1    );
      } // THEN
    } // WHEN
    WHEN( "optional card4 inputs not provided" ){
      iRecordStream<char> is( std::istringstream( "1 1001 /" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card4 card4( is );
        REQUIRE( card4.mat.value   == 1    );
        REQUIRE( card4.za.value    == 1001 );
        REQUIRE( card4.isabt.value == 0    );
        REQUIRE( card4.ilog.value  == 0    );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid card4 inputs" ){
    WHEN( "card4 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( "-1  1001   1  1" ) );
      iRecordStream<char> is2( std::istringstream( "1   999    1  1" ) );
      iRecordStream<char> is3( std::istringstream( "1   1001  -1  1" ) );
      iRecordStream<char> is4( std::istringstream( "1   1001   1 -1" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card4( is1 ) );
        REQUIRE_THROWS( LEAPR::Card4( is2 ) );
        REQUIRE_THROWS( LEAPR::Card4( is3 ) );
        REQUIRE_THROWS( LEAPR::Card4( is4 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

