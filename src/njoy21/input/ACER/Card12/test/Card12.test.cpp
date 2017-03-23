#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card12 input", "[ACER], [Card12]" ){
  GIVEN( "valid material and temperature" ){
    iRecordStream<char> issCard12( std::istringstream( " 9235 " ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card12 card12 ( issCard12 );
      REQUIRE( 9235 == card12.matd.value );
    }
  } // GIVEN

  GIVEN( "invalid Card12 input" ){
    iRecordStream<char> issCard12( std::istringstream( " -9235" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card12 card12( issCard12 ) );
      }

  } // GIVEN
} // SCENARIO

