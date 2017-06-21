#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying MIXR Card4 input" ){
  GIVEN( "valid MIXR Card4 inputs" ){
    iRecordStream<char> iss( std::istringstream("293.6") );
    MIXR::Card4 card4( iss );

    THEN( "the members can be tested" ){
      REQUIRE( 293.6 * dimwits::kelvin == card4.temp.value);
    }
  }
  GIVEN( "invalid MIXR Card4 inputs" ){
    iRecordStream<char> iss( std::istringstream("-293.6") );
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( MIXR::Card4( iss ) );
    }
  }
}
