#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying GROUPR Card6a input", "[GROUPR], [Card6a]" ){
  GIVEN( "valid  Card6a" ){
    iRecordStream<char> issCard6a( std::istringstream( "618" ) );
    GROUPR::Card6a card6a( issCard6a );

    THEN( "the ngn parameter can be verified" ){
      REQUIRE( 618 == card6a.ngn.value );
    }
  }
  GIVEN( "invalid Card6a" ){
    iRecordStream<char> issCard6a( std::istringstream( "-618" ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card6a( issCard6a ) );
    }
  }
} // SCENARIO
