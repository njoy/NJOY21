#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card7 inputs", "[GAMINR], [Card7]" ){
  GIVEN( "'normal' material number" ){
    iRecordStream<char> issCard7( std::istringstream( "9238 /" ) );
    GAMINR::Card7 card7( issCard7 );

    THEN( "the card7 value can be verified" ){
      REQUIRE( 9238 == card7.matd.value );
    }
  }
  GIVEN( "terminating material number" ){
    iRecordStream<char> issCard7( std::istringstream( "0 /" ) );
    GAMINR::Card7 card7( issCard7 );

    THEN( "the card7 values can be verified" ){
      REQUIRE( 0 == card7.matd.value );
    }
  }

  GIVEN( "invalid Card7 input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard7( std::istringstream( " -1 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card7( issCard7 ) );
      }
    }
  }
} // SCENARIO
