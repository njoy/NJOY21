#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card11 input values",
  "[LEAPR], [Card11]" ){
  GIVEN( "valid card11 inputs" ){
    iRecordStream<char> is( std::istringstream( "20 30" ) );
    THEN( "the extracted values are correct" ){
      LEAPR::Card11 card11( is );
      REQUIRE( card11.delta.value == 20 * dimwits::electronVolts );
      REQUIRE( card11.ni.value    == 30 );
    } // THEN
  } // GIVEN
  GIVEN( "invalid card11 inputs" ){
    WHEN( "card11 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( " 0 30" ) );
      iRecordStream<char> is2( std::istringstream( "20  0" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card11( is1 ) );
        REQUIRE_THROWS( LEAPR::Card11( is2 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

