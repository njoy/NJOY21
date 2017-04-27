#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card8a inputs", "[GROUPR], [Card8d]" ){
  WHEN( "all optional values are are given" ){
    iRecordStream<char> issCard8d( std::istringstream( "22 /" ));
    GROUPR::Card8d card8a( issCard8d );

    THEN( "the card8a values can be verified" ){
      REQUIRE( 22 == card8a.ninwt.value );
    }
  }
  GIVEN( "invalid Card8d input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard8d( std::istringstream( " -19 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GROUPR::Card8d(issCard8d ) );
      }
    }
  }
} // SCENARIO
