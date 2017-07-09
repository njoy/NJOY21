#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card8a inputs", "[GROUPR], [Card8c]" ){
  WHEN( "all optional values are are given" ){
    iRecordStream<char> issCard8c( 
        std::istringstream( ".10 .025 820.3e3 1.4e6 /" ));
    GROUPR::Card8c card8c( issCard8c );

    THEN( "the card8a values can be verified" ){
      REQUIRE( 0.10*dimwits::electronVolt == card8c.eb.value );
      REQUIRE( 0.025*dimwits::electronVolt == card8c.tb.value );
      REQUIRE( 820.3E3*dimwits::electronVolt == card8c.ec.value );
      REQUIRE( 1.4E6*dimwits::electronVolt == card8c.tc.value );
    }
  }
  GIVEN( "invalid Card8c input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard8c( std::istringstream( " -19. /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GROUPR::Card8c(issCard8c ) );
      }
    }
  }
} // SCENARIO
