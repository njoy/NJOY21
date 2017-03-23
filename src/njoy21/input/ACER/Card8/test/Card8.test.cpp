#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card8 input", "[ACER], [Card8]" ){
  GIVEN( "valid material, temperature, and name" ){
    iRecordStream<char> issCard8( std::istringstream( " 1 293.6 'lwtr'" ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card8 card8 ( issCard8 );
      REQUIRE( 1 == card8.matd.value );
      REQUIRE( 293.6* dimwits::kelvin == card8.tempd.value );
      REQUIRE( "lwtr" == card8.tname.value );
    }
  } // GIVEN
  GIVEN( "only material and temperature" ){
    iRecordStream<char> issCard8( 
        std::istringstream( " 1 293.6  /" ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card8 card8 ( issCard8 );
      REQUIRE( 1 == card8.matd.value );
      REQUIRE( 293.6* dimwits::kelvin == card8.tempd.value );
      REQUIRE( "      " == card8.tname.value );
    }
  } // GIVEN

  GIVEN( "invalid Card8 input" ){
    WHEN( "invalid entries" ){
    iRecordStream<char> issCard8( 
        std::istringstream( " 1 293.6 'abcdefghij' /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card8 card8( issCard8 ) );
      }

    }
  } // GIVEN
} // SCENARIO


