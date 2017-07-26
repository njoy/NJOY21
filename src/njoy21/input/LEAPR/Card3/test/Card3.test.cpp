#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "nout input values",
  "[LEAPR], [Card3]" ){
  GIVEN( "valid card3 inputs" ){
    WHEN( "all card3 inputs provided" ){
      iRecordStream<char> is( std::istringstream( "2 0 99" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card3 card3( is );
        REQUIRE( card3.ntempr.value == 2 );
        REQUIRE( card3.iprint.value == 0 );
        REQUIRE( card3.nphon.value  == 99 );
      } // THEN
    } // WHEN
    WHEN( "optional card3 inputs not provided" ){
      iRecordStream<char> is( std::istringstream( "/" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card3 card3( is );
        REQUIRE( card3.ntempr.value == 1 );
        REQUIRE( card3.iprint.value == 1 );
        REQUIRE( card3.nphon.value  == 100 );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid card3 inputs" ){
    WHEN( "card3 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( "-1 0 99" ) );
      iRecordStream<char> is2( std::istringstream( "0 4 99" ) );
      iRecordStream<char> is3( std::istringstream( "0 0 0" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card3( is1 ) );
        REQUIRE_THROWS( LEAPR::Card3( is2 ) );
        REQUIRE_THROWS( LEAPR::Card3( is3 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

