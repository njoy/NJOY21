#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card5 inputs",
  "[DFTR], [Card5]" ){
  GIVEN( "valid Ned input value" ){
    Argument< DTFR::Card3::Ned > ned;
    ned.value = 6;

    WHEN( "all DTFR inputs provided are valid" ){
      iRecordStream<char> iss( std::istringstream( "1 91 3" ) );
      DTFR::Card5 card5( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( 1  == card5.jpos.value );
        REQUIRE( 91 == card5.mt.value );
        REQUIRE( 3  == card5.mult.value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid Ned input value" ){
    Argument< DTFR::Card3::Ned > ned;
    ned.value = 6;

    WHEN( "not all DTFR inputs provided are valid" ){
      iRecordStream<char> iss( std::istringstream( "-1 91 3" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card5( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
