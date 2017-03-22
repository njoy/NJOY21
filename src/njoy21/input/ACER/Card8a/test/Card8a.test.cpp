#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card8 input", "[ACER], [Card8a]" ){
  GIVEN( "all entries given" ){
    iRecordStream<char> issCard8a( std::istringstream( " 1001 6012 6000 /" ) );

    THEN( "the iza values can be extracted and verified" ){
      ACER::Card8a  card8a( issCard8a );
      REQUIRE( 1001 == card8a.iza01.value );
      REQUIRE( 6012 == card8a.iza02.value );
      REQUIRE( 6000 == card8a.iza03.value );
    }
  }
  GIVEN( "only iza01 and iza02 given" ){
    iRecordStream<char> issCard8a( std::istringstream( " 1001 6012 /" ) );

    THEN( "the iza values can be extracted and verified" ){
      ACER::Card8a  card8a( issCard8a );
      REQUIRE( 1001 == card8a.iza01.value );
      REQUIRE( 6012 == card8a.iza02.value );
      REQUIRE( 0    == card8a.iza03.value );
    }
  }
  GIVEN( "only iza01 given" ){
    iRecordStream<char> issCard8a( std::istringstream( " 1001 /" ) );

    THEN( "the iza values can be extracted and verified" ){
      ACER::Card8a  card8a( issCard8a );
      REQUIRE( 1001 == card8a.iza01.value );
      REQUIRE( 0    == card8a.iza02.value );
      REQUIRE( 0    == card8a.iza03.value );
    }
  }
  GIVEN( "invalid Card8a input" ){
    iRecordStream<char> issCard8a( std::istringstream( " -1001 /" ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( ACER::Card8a card8a( issCard8a ) );
    }
  }
}
