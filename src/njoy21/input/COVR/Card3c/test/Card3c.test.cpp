#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR Card3c",
  "[COVR], [Card3c]"){

  GIVEN( "valid (short) card3c entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "h" ) );
      COVR::Card3c card3c( iss );
      REQUIRE( "h" == card3c.hdescr.value );
    } // THEN
  } // GIVEN

  GIVEN( "valid (medium) card3c entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 1'" ) );
      COVR::Card3c card3c( iss );
      REQUIRE( "123456789 123456789 1" == card3c.hdescr.value );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) card3c entry" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 12'"  ) );
      REQUIRE_THROWS( COVR::Card3c( iss ) );
    } // THEN
  } // GIVEN
} // SCENARIO
