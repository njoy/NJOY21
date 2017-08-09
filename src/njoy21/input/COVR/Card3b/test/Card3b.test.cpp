#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR Card3b",
  "[COVR], [Card3b]"){

  GIVEN( "valid (short) card3b entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "h" ) );
      COVR::Card3b card3b( iss );
      REQUIRE( "h" == card3b.hlibid.value );
    } // THEN
  } // GIVEN

  GIVEN( "valid (medium) card3b entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "hlibid" ) );
      COVR::Card3b card3b( iss );
      REQUIRE( "hlibid" == card3b.hlibid.value );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) card3b entry" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( "toolong"  ) );
      REQUIRE_THROWS( COVR::Card3b( iss ) );
    } // THEN
  } // GIVEN
} // SCENARIO
