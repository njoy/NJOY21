#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "nout input values",
  "[LEAPR], [Card7]" ){
  GIVEN( "valid card7 inputs" ){
    WHEN( "all card7 inputs provided" ){
      iRecordStream<char> is( std::istringstream( "20 30 1" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card7 card7( is );
        REQUIRE( card7.nalpha.value == 20 );
        REQUIRE( card7.nbeta.value  == 30 );
        REQUIRE( card7.lat.value    == 1  );
      } // THEN
    } // WHEN
    WHEN( "optional card7 input not provided" ){
      iRecordStream<char> is( std::istringstream( "20 30 /" ) );
      THEN( "the extracted values are correct" ){
        LEAPR::Card7 card7( is );
        REQUIRE( card7.nalpha.value == 20 );
        REQUIRE( card7.nbeta.value  == 30 );
        REQUIRE( card7.lat.value    == 0  );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid card7 inputs" ){
    WHEN( "card7 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( " 0 30 1" ) );
      iRecordStream<char> is2( std::istringstream( "20  0 1" ) );
      iRecordStream<char> is3( std::istringstream( "20 30 2" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card7( is1 ) );
        REQUIRE_THROWS( LEAPR::Card7( is2 ) );
        REQUIRE_THROWS( LEAPR::Card7( is3 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

