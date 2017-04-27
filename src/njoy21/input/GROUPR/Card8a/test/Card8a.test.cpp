#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card8a inputs", "[GROUPR], [Card8a]" ){
  WHEN( "all optional values are are given" ){
    iRecordStream<char> issCard8a( 
        std::istringstream( "400 10.6 5000 0 0 0.7768 7.5 0.40 1.6E-7 0.086 /") 
        );
    GROUPR::Card8a card8a( issCard8a );

    THEN( "the card8a values can be verified" ){
      REQUIRE( 400*dimwits::electronVolt == card8a.fehi.value );
      REQUIRE( 10.6*dimwits::barn == card8a.sigpot.value );
      REQUIRE( 5000 == card8a.nflmax.value );
      REQUIRE( 0 == card8a.ninwt.value );
      REQUIRE( 0 == card8a.jsigz.value );
      REQUIRE( 0.7768 == card8a.alpha2.value );
      REQUIRE( 7.5*dimwits::barn == card8a.sam.value );
      REQUIRE( 0.40 == card8a.beta.value );
      REQUIRE( 1.6E-7 == card8a.alpha3.value );
      REQUIRE( 0.086 == card8a.gamma.value );
    }
  }
  WHEN( "none of the optional values are given" ){
    iRecordStream<char> issCard8a( std::istringstream( "400 10.6 5000 /" ) );
    GROUPR::Card8a card8a( issCard8a );

    THEN( "the card8a values can be verified" ){
      REQUIRE( 400*dimwits::electronVolt == card8a.fehi.value );
      REQUIRE( 10.6*dimwits::barn == card8a.sigpot.value );
      REQUIRE( 5000 == card8a.nflmax.value );
      REQUIRE( 0 == card8a.ninwt.value );
      REQUIRE( 0 == card8a.jsigz.value );
      REQUIRE( 0.0 == card8a.alpha2.value );
      REQUIRE( 0.0*dimwits::barn == card8a.sam.value );
      REQUIRE( 0.0 == card8a.beta.value );
      REQUIRE( 0.0 == card8a.alpha3.value );
      REQUIRE( 0.0 == card8a.gamma.value );
    }
  }

  GIVEN( "invalid Card8a input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard8a( std::istringstream( " 3 -1 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GROUPR::Card8a(issCard8a ) );
      }
    }
  }
} // SCENARIO
