#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR Card4 inputs",
  "[THERMR], [Card4] "){
  GIVEN( "valid Card4 inputs" ){
    WHEN( "all values provided" ){
      iRecordStream<char> is( std::istringstream(".01 4.6") );
      THEN( "the extracted values are correct" ){
        THERMR::Card4 card4( is );
        REQUIRE( card4.tol.value == 0.01 );
        REQUIRE( card4.emax.value == 4.6 );
      } // THEN 
    } // WHEN
  } // GIVEN
  
  GIVEN( "invalid Card4 inputs" ){
    WHEN( "an card4 input is out of range" ){
      iRecordStream<char> is1( std::istringstream("1e-6 4.5") );
      iRecordStream<char> is2( std::istringstream("0.05 0.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card4( is1 ) );
        REQUIRE_THROWS( THERMR::Card4( is2 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
