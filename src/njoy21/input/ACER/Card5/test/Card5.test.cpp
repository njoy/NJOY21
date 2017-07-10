#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card5 input",
          "[ACER], [Card5]" ){
  GIVEN( "valid material and temperature" ){
    iRecordStream<char> issCard5( 
        std::istringstream( " 9235 293.6" ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card5 card5 ( issCard5 );
      REQUIRE( 9235 == card5.matd.value );
      REQUIRE( 293.6* dimwits::kelvin == card5.tempd.value );
    }
  } // GIVEN

  GIVEN( "invalid Card5 input" ){
    WHEN( "there is no temperature" ){
    iRecordStream<char> issCard5( 
        std::istringstream( " 9235" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card5( issCard5 ) );
      }

    }
  } // GIVEN
} // SCENARIO

