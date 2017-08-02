#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "nout input values",
  "[LEAPR], [Card13]" ){
  GIVEN( "valid card13 inputs" ){
    iRecordStream<char> is( std::istringstream( "0.0 1.0 1.0" ) );
    THEN( "the extracted values are correct" ){
      LEAPR::Card13 card13( is );
      REQUIRE( card13.twt.value   == 0.0 );
      REQUIRE( card13.c.value     == 1.0 );
      REQUIRE( card13.tbeta.value == 1.0 );
    } // THEN
  } // GIVEN
  GIVEN( "invalid card13 inputs" ){
    WHEN( "card13 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( "-0.1 0.0 1.0" ) );
      iRecordStream<char> is2( std::istringstream( "0.0 -0.1 1.0" ) );
      iRecordStream<char> is3( std::istringstream( "0.0  0.0 0.0" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card13( is1 ) );
        REQUIRE_THROWS( LEAPR::Card13( is2 ) );
        REQUIRE_THROWS( LEAPR::Card13( is3 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

