#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR hdescr",
  "[COVR], [Card3c], [Hdescr]"){

  GIVEN( "valid (short) hdescr entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "h" ) );
      REQUIRE( "h" == argument::extract< 
        COVR::Card3c::Hdescr >( iss ).value);
    } // THEN
  } // GIVEN

  GIVEN( "valid (medium) hdescr entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 1'" ) );
      REQUIRE( "123456789 123456789 1" == argument::extract< 
        COVR::Card3c::Hdescr >( iss ).value );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) hdescr values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 12'"  ) );
      REQUIRE_THROWS( argument::extract< 
        COVR::Card3c::Hdescr >( iss ) );
    } // THEN
  } // GIVEN
} // SCENARIO
