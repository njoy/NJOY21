#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "nout input values",
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
      iRecordStream<char> is1LO( std::istringstream( "-1  1001   1  1" ) );
      iRecordStream<char> is1HI( std::istringstream( "101 1001   1  1" ) );
      iRecordStream<char> is2LO( std::istringstream( "1   999    1  1" ) );
      iRecordStream<char> is2HI( std::istringstream( "1   200000 1  1" ) );
      iRecordStream<char> is3LO( std::istringstream( "1   1001  -1  1" ) );
      iRecordStream<char> is3HI( std::istringstream( "1   1001   2  1" ) );
      iRecordStream<char> is4LO( std::istringstream( "1   1001   1 -1" ) );
      iRecordStream<char> is4HI( std::istringstream( "1   1001   1  2" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card4( is1LO ) );
        REQUIRE_THROWS( LEAPR::Card4( is1HI ) );
        REQUIRE_THROWS( LEAPR::Card4( is2LO ) );
        REQUIRE_THROWS( LEAPR::Card4( is2HI ) );
        REQUIRE_THROWS( LEAPR::Card4( is3LO ) );
        REQUIRE_THROWS( LEAPR::Card4( is3HI ) );
        REQUIRE_THROWS( LEAPR::Card4( is4LO ) );
        REQUIRE_THROWS( LEAPR::Card4( is4HI ) );

      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

