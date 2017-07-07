#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card5 inputs",
  "[MIXR],[Card5]"){
  GIVEN( "valid MIXR Card5 inputs" ){
    iRecordStream<char> iss( std::istringstream( "2600 26000 56." ) );
    MIXR::Card5 card5( iss );
    THEN( "the members can be tested" ){
      REQUIRE( 2600 == card5.matd.value );
      REQUIRE( 26000 == card5.za.value );
      REQUIRE( 56. == card5.awr.value );
     }
  }
  GIVEN( "invalid MIXR Card5 input" ){
    iRecordStream<char> iss( std::istringstream( "0 -26000 56." ) );
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( MIXR::Card5( iss ) );
    }
  }
}

