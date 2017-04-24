#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card10 input",
          "[ACER], [Card10]" ){
  GIVEN( "valid material and temperature" ){
    iRecordStream<char> issCard10( 
        std::istringstream( " 9235 293.6" ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card10 card10 ( issCard10 );
      REQUIRE( 9235 == card10.matd.value );
      REQUIRE( 293.6* dimwits::kelvin == card10.tempd.value );
    }
  } // GIVEN

  GIVEN( "invalid Card10 input" ){
    WHEN( "there is no temperature" ){
    iRecordStream<char> issCard10( 
        std::istringstream( " 9235" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card10( issCard10 ) );
      }

    }
  } // GIVEN
} // SCENARIO

