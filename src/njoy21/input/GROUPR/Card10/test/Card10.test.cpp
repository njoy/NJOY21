#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card10 inputs", "[GROUPR], [Card10]" ){
  GIVEN( "'normal' material number" ){
    iRecordStream<char> issCard10( std::istringstream( "9238 /" ) );
    GROUPR::Card10 card10( issCard10 );

    THEN( "the card10 value can be verified" ){
      REQUIRE( 9238 == card10.matd.value );
    }
  }
  GIVEN( "terminating material number" ){
    iRecordStream<char> issCard10( std::istringstream( "0 /" ) );
    GROUPR::Card10 card10( issCard10 );

    THEN( "the card10 values can be verified" ){
      REQUIRE( 0 == card10.matd.value );
    }
  }

  GIVEN( "invalid Card10 input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard10( std::istringstream( " -1 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GROUPR::Card10(issCard10 ) );
      }
    }
  }
} // SCENARIO
