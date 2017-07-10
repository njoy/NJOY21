#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying GROUPR Card7a input", "[GROUPR], [Card7a]" ){
  GIVEN( "valid  Card7a" ){
    iRecordStream<char> issCard7a( std::istringstream( "618" ) );
    GROUPR::Card7a card7a( issCard7a );

    THEN( "the ngg parameter can be verified" ){
      REQUIRE( 618 == card7a.ngg.value );
    }
  }
  GIVEN( "invalid Card7a" ){
    iRecordStream<char> issCard7a( std::istringstream( "-618" ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card7a( issCard7a ) );
    }
  }
} // SCENARIO
